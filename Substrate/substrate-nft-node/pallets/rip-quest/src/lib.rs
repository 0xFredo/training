#![cfg_attr(not(feature = "std"), no_std)]

pub use pallet::*;

#[frame_support::pallet]
pub mod pallet {
	use frame_support::pallet_prelude::*;
	use frame_support::{
		sp_runtime::traits::Hash,
		traits::{tokens::ExistenceRequirement, Currency, Randomness},
		transactional,
	};
	use frame_system::pallet_prelude::*;
	use scale_info::TypeInfo;
	use sp_io::hashing::blake2_128;

	use sp_std::vec::Vec;
	use sp_std::str;

	#[cfg(feature = "std")]
	use frame_support::serde::{Deserialize, Serialize};

	type AccountOf<T> = <T as frame_system::Config>::AccountId;
	type BalanceOf<T> =
		<<T as Config>::Currency as Currency<<T as frame_system::Config>::AccountId>>::Balance;

	// Struct for holding Belt information.
	#[derive(Clone, Encode, Decode, PartialEq, RuntimeDebug, TypeInfo, MaxEncodedLen)]
	#[scale_info(skip_type_params(T))]
	#[codec(mel_bound())]
	pub struct Belt<T: Config> {
		pub serial_num: [u8; 16], // Using 16 bytes to represent a belt serial number
		pub price: Option<BalanceOf<T>>,
		pub belt_type: BeltType,
		pub owner: AccountOf<T>,
	}

	// Set pic_link type in Belt struct.
	#[derive(Clone, Encode, Decode, PartialEq, RuntimeDebug, TypeInfo, MaxEncodedLen)]
	#[cfg_attr(feature = "std", derive(Serialize, Deserialize))]
	pub enum BeltType {
		ChastityBelt,
		FanBelt,
		WhiteBelt,
		WrongBelt,
	}
	
	#[pallet::pallet]
	#[pallet::generate_store(pub(super) trait Store)]
	pub struct Pallet<T>(_);

	// Configure the pallet by specifying the parameters and types on which it depends.
	#[pallet::config]
	pub trait Config: frame_system::Config {
		/// Because this pallet emits events, it depends on the runtime's definition of an event.
		type Event: From<Event<Self>> + IsType<<Self as frame_system::Config>::Event>;

		/// The Currency handler for the RipQuest pallet.
		type Currency: Currency<Self::AccountId>;

		/// The maximum amount of Belts a single account can own.
		#[pallet::constant]
		type MaxBeltOwned: Get<u32>;

		/// The type of Randomness we want to specify for this pallet.
		type BeltRandomness: Randomness<Self::Hash, Self::BlockNumber>;
	}

	// Errors.
	#[pallet::error]
	pub enum Error<T> {
		/// Handles arithmetic overflow when incrementing the Belt counter.
		BeltCntOverflow,
		/// An account cannot own more Belt than `MaxBeltCount`.
		ExceedMaxBeltOwned,
		/// Buyer cannot be the owner.
		BuyerIsBeltOwner,
		/// Cannot transfer a belt to its owner.
		TransferToSelf,
		/// This belt already exists
		BeltExists,
		/// This Belt doesn't exist
		BeltNotExist,
		/// Handles checking that the Belt is owned by the account transferring, buying or setting a price for it.
		NotBeltOwner,
		/// Ensures the Belt is for sale.
		BeltNotForSale,
		/// Ensures that the buying price is greater than the asking price.
		BeltBidPriceTooLow,
		/// Ensures that an account has enough funds to purchase a Belt.
		NotEnoughBalance,
	}

	// Events.
	#[pallet::event]
	#[pallet::generate_deposit(pub(super) fn deposit_event)]
	pub enum Event<T: Config> {
		/// A new Belt was successfully created. \[sender, belt_id\]
		Created(T::AccountId, T::Hash),
		/// Belt price was successfully set. \[sender, belt_id, new_price\]
		PriceSet(T::AccountId, T::Hash, Option<BalanceOf<T>>),
		/// A Belt was successfully transferred. \[from, to, belt_id\]
		Transferred(T::AccountId, T::AccountId, T::Hash),
		/// A Belt was successfully bought. \[buyer, seller, belt_id, bid_price\]
		Bought(T::AccountId, T::AccountId, T::Hash, BalanceOf<T>),
	}

	// Storage items.

	#[pallet::storage]
	#[pallet::getter(fn belt_cnt)]
	/// Keeps track of the number of Belts in existence.
	pub(super) type BeltCnt<T: Config> = StorageValue<_, u64, ValueQuery>;

	#[pallet::storage]
	#[pallet::getter(fn belts)]
	/// Stores a Belt's unique traits, owner and price.
	pub(super) type Belts<T: Config> = StorageMap<_, Twox64Concat, T::Hash, Belt<T>>;

	#[pallet::storage]
	#[pallet::getter(fn belts_owned)]
	/// Keeps track of what accounts own what Belt.
	pub(super) type BeltsOwned<T: Config> = StorageMap<
		_,
		Twox64Concat,
		T::AccountId,
		BoundedVec<T::Hash, T::MaxBeltOwned>,
		ValueQuery,
	>;

	// Our pallet's genesis configuration.
	#[pallet::genesis_config]
	pub struct GenesisConfig<T: Config> {
		pub belts: Vec<(T::AccountId, [u8; 16], BeltType)>,
	}

	// Required to implement default for GenesisConfig.
	#[cfg(feature = "std")]
	impl<T: Config> Default for GenesisConfig<T> {
		fn default() -> GenesisConfig<T> {
			GenesisConfig { belts: vec![] }
		}
	}

	#[pallet::genesis_build]
	impl<T: Config> GenesisBuild<T> for GenesisConfig<T> {
		fn build(&self) {
			// When building a belt from genesis config, we require the serial_num to be supplied.
			for (acct, serial_num, belt_type) in &self.belts {
				let _ = <Pallet<T>>::mint(acct, Some(serial_num.clone()), belt_type.clone());
			}
		}
	}

	#[pallet::call]
	impl<T: Config> Pallet<T> {
		/// Create a new unique belt. Provide hashed (sha256) rip link to get the related belt.
		///
		/// The actual belt creation is done in the `mint()` function.
		#[pallet::weight(100)]
		pub fn create_belt(origin: OriginFor<T>, rip_link_sha256: Vec<u8>) -> DispatchResult {
			let sender = ensure_signed(origin)?;
			let belt_type = Self::get_belt_type(&rip_link_sha256);

			let belt_id = Self::mint(&sender, None, belt_type)?;
			log::info!("A belt is crafted with ID: {:?}.", belt_id);

			Self::deposit_event(Event::Created(sender, belt_id));
			Ok(())
		}


		/// Set the price for a Belt.
		///
		/// Updates Belt price and updates storage.
		#[pallet::weight(100)]
		pub fn set_price(
			origin: OriginFor<T>,
			belt_id: T::Hash,
			new_price: Option<BalanceOf<T>>,
		) -> DispatchResult {
			let sender = ensure_signed(origin)?;

			ensure!(Self::is_belt_owner(&belt_id, &sender)?, <Error<T>>::NotBeltOwner);

			let mut belt = Self::belts(&belt_id).ok_or(<Error<T>>::BeltNotExist)?;

			belt.price = new_price.clone();
			<Belts<T>>::insert(&belt_id, belt);

			// Deposit a "PriceSet" event.
			Self::deposit_event(Event::PriceSet(sender, belt_id, new_price));

			Ok(())
		}

		#[pallet::weight(100)]
		pub fn transfer(
			origin: OriginFor<T>,
			to: T::AccountId,
			belt_id: T::Hash,
		) -> DispatchResult {
			let from = ensure_signed(origin)?;

			// Ensure the belt exists and is called by the belt owner
			ensure!(Self::is_belt_owner(&belt_id, &from)?, <Error<T>>::NotBeltOwner);

			// Verify the belt is not transferring back to its owner.
			ensure!(from != to, <Error<T>>::TransferToSelf);

			// Verify the recipient has the capacity to receive one more belt
			let to_owned = <BeltsOwned<T>>::get(&to);
			ensure!(
				(to_owned.len() as u32) < T::MaxBeltOwned::get(),
				<Error<T>>::ExceedMaxBeltOwned
			);

			Self::transfer_belt_to(&belt_id, &to)?;

			Self::deposit_event(Event::Transferred(from, to, belt_id));

			Ok(())
		}

		// buy_belt
		#[transactional]
		#[pallet::weight(100)]
		pub fn buy_belt(
			origin: OriginFor<T>,
			belt_id: T::Hash,
			bid_price: BalanceOf<T>,
		) -> DispatchResult {
			let buyer = ensure_signed(origin)?;

			// Check the belt exists and buyer is not the current belt owner
			let belt = Self::belts(&belt_id).ok_or(<Error<T>>::BeltNotExist)?;
			ensure!(belt.owner != buyer, <Error<T>>::BuyerIsBeltOwner);

			// Check the belt is for sale and the belt ask price <= bid_price
			if let Some(ask_price) = belt.price {
				ensure!(ask_price <= bid_price, <Error<T>>::BeltBidPriceTooLow);
			} else {
				Err(<Error<T>>::BeltNotForSale)?;
			}

			// Check the buyer has enough free balance
			ensure!(T::Currency::free_balance(&buyer) >= bid_price, <Error<T>>::NotEnoughBalance);

			// Verify the buyer has the capacity to receive one more belt
			let to_owned = <BeltsOwned<T>>::get(&buyer);
			ensure!(
				(to_owned.len() as u32) < T::MaxBeltOwned::get(),
				<Error<T>>::ExceedMaxBeltOwned
			);

			let seller = belt.owner.clone();

			// Transfer the amount from buyer to seller
			T::Currency::transfer(&buyer, &seller, bid_price, ExistenceRequirement::KeepAlive)?;

			// Transfer the belt from seller to buyer
			Self::transfer_belt_to(&belt_id, &buyer)?;

			// Deposit relevant Event
			Self::deposit_event(Event::Bought(buyer, seller, belt_id, bid_price));

			Ok(())
		}
	}

	//**Helper functions.**//

	impl<T: Config> Pallet<T> {

		fn gen_serial_num() -> [u8; 16] {
			let payload = (
				T::BeltRandomness::random(&b"serial_num"[..]).0,
				<frame_system::Pallet<T>>::extrinsic_index().unwrap_or_default(),
				<frame_system::Pallet<T>>::block_number(),
			);
			payload.using_encoded(blake2_128)
		}

		fn get_belt_type(rip_link_sha256: &Vec<u8>) -> BeltType {

			let quest_step_1 = "98d44e13f455d916674d38424d39e1cb01b2a9132aacbb7b97a6f8bb7feb2544";
			let quest_step_2 = "d516dbecbf6a8cb4d28185bdd60f8faf9c0ceb8e8eabfb987206795e87281310";
			let quest_step_3 = "c1ae890f8007f45103aa36b98ec1ba99d23a38813b9a123772f9306a1e575b93";

			let rip_link_sha256 = str::from_utf8(rip_link_sha256).unwrap();

			if rip_link_sha256 == quest_step_1 {
				BeltType::ChastityBelt
			} else if rip_link_sha256 == quest_step_2 {
				BeltType::FanBelt
			} else if rip_link_sha256 == quest_step_3 {
				BeltType::WhiteBelt
			} else {
				BeltType::WrongBelt
			}
		}

		//TODO: assign pic to belt
		/*fn get_pic_link(belt_type: &BeltType) -> Vec<u8> {
			match belt_type {
				BeltType::ChastityBelt => "https://cdn.vectorstock.com/i/1000x1000/16/77/chastity-belt-torture-device-sketch-vector-27351677.webp",
				BeltType::FansBelt     => "https://www.scparts.co.uk/media/catalog/product/cache/5/image/9df78eab33525d08d6e5fb8d27136e95/9/2/92509.jpg",
				BeltType::WhiteBelt    => "https://www.centurymartialarts.com/product/image/large/011_100_1.jpg",
								     _ => "https://www.hallofseries.com/wp-content/uploads/2017/10/STANISBOPNUS.jpg",
			}
		}*/

		// Helper to mint a Belt.
		pub fn mint(
			owner: &T::AccountId,
			serial_num: Option<[u8; 16]>,
			belt_type: BeltType,
		) -> Result<T::Hash, Error<T>> {		
			let belt = Belt::<T> {
				serial_num: serial_num.unwrap_or_else(Self::gen_serial_num),
				price: None,
				belt_type: belt_type,
				owner: owner.clone(),
			};

			let belt_id = T::Hashing::hash_of(&belt);

			// Performs this operation first as it may fail
			let new_cnt = Self::belt_cnt().checked_add(1).ok_or(<Error<T>>::BeltCntOverflow)?;

			// Check if the belt does not already exist in our storage map
			ensure!(Self::belts(&belt_id) == None, <Error<T>>::BeltExists);

			// Performs this operation first because as it may fail
			<BeltsOwned<T>>::try_mutate(&owner, |belt_vec| belt_vec.try_push(belt_id))
				.map_err(|_| <Error<T>>::ExceedMaxBeltOwned)?;

			<Belts<T>>::insert(belt_id, belt);
			<BeltCnt<T>>::put(new_cnt);
			Ok(belt_id)
		}

		pub fn is_belt_owner(belt_id: &T::Hash, acct: &T::AccountId) -> Result<bool, Error<T>> {
			match Self::belts(belt_id) {
				Some(belt) => Ok(belt.owner == *acct),
				None => Err(<Error<T>>::BeltNotExist),
			}
		}

		#[transactional]
		pub fn transfer_belt_to(belt_id: &T::Hash, to: &T::AccountId) -> Result<(), Error<T>> {
			let mut belt = Self::belts(&belt_id).ok_or(<Error<T>>::BeltNotExist)?;

			let prev_owner = belt.owner.clone();

			// Remove `belt_id` from the BeltsOwned vector of `prev_owner`
			<BeltsOwned<T>>::try_mutate(&prev_owner, |owned| {
				if let Some(ind) = owned.iter().position(|&id| id == *belt_id) {
					owned.swap_remove(ind);
					return Ok(());
				}
				Err(())
			})
			.map_err(|_| <Error<T>>::BeltNotExist)?;

			// Update the belt owner
			belt.owner = to.clone();
			// Reset the ask price so the belt is not for sale until `set_price()` is called
			// by the current owner.
			belt.price = None;

			<Belts<T>>::insert(belt_id, belt);

			<BeltsOwned<T>>::try_mutate(to, |vec| vec.try_push(*belt_id))
				.map_err(|_| <Error<T>>::ExceedMaxBeltOwned)?;

			Ok(())
		}
	}
}
