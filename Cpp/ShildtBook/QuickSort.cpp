
#include <iostream>
#include <cstring>

template <class T> void quicksort(T *items, int len);
template <class T> void qs(T *items, int left, int right);

int main()
{
	char str[] = "tlube";
	std::cout << "Original: " << str << "\n";

	quicksort(str, strlen(str));

	std::cout << "Sorted: " << str << "\n";

	int nums[] = {1,4,2,8,3,5,9};
	int len = sizeof(nums) / sizeof(*nums);
	for(int i = 0; i < len; i++)
		std::cout << nums[i] << " ";

	std::cout << "\n";

	quicksort(nums, len);

	for(int i = 0; i < len; i++)
		std::cout << nums[i] << " ";

	return 0;
}


//interface
template <class T> void quicksort(T *items, int len)
{
	qs(items, 0, len - 1);
}

//Recursive function
template <class T> void qs(T *items, int left, int right)
{
	int i, j;
	T comparand, tmp;

	i = left;
	j = right;

	comparand = items[(left+right) / 2];

	do
	{
		std::cout << "Array transformation: " << items << "\n";
		while( (items[i] < comparand) && (i < right) ) i++;
		while( (comparand < items[j]) && (j  > left) ) j--;

		if(i <= j)
		{
			tmp = items[i];
			items[i] = items[j];
			items[j] = tmp;

			i++; j--;
		}
	} while(i <= j);

	if(left < j) qs(items, left, j);
	if(i < right) qs(items, i, right);
}