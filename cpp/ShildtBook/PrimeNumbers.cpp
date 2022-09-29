#include <iostream>

int main()
{
	//iterate from 1 to 100
	//divide each number from 2 to itself-1, if all the reminder are not 0 print that number as a prime number

	for(int i = 1; i <= 100; i++)
	{
		bool isPrime = true;
		for(int j = i; j > 1; j--)
		{	
			int divider = j - 1;
			if( (divider != 1) && (i % divider == 0))
				isPrime = false;
		}

		if(isPrime)
			std::cout << i << "\n";
	}

	return 0;
}


/* better solution
using namespace std; 
int main() { 
	int i, j; 
	bool isprime; 
	for(i=1; i < 100; i++) { 
		isprime = true; 
		// see if the number is evenly divisible 
		for(j=2; j <= i/2; j++) 
			// if it is, then it is not prime 
			if((i%j) == 0) isprime = false; 
			
		if(isprime) 
			cout << i << " is prime.\n"; 
	} 
	return 0; 
} 