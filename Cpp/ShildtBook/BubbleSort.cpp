#include <iostream>
#include <cstdlib>
/*
	Project 4-1 Bubble sort
*/

int main()
{
	int nums[10];
	int size = 10;

	for(int i = 0; i < size; i++) nums[i] = rand();

	std::cout << "Original array: ";
	for(int i = 0; i < size; i++) std::cout << nums[i] << ' ';
	std::cout << "\n";

	for(int i = 1; i < size; i++)
	{
		for(int j = size-1; j >= i; j--)
		{
			if(nums[j-1] > nums[j])
			{
				int tmp = nums[j-1];
				nums[j-1] = nums[j];
				nums[j] = tmp;
			}
		}
	}

	std::cout << "Sorted array: ";
	for(int i = 0; i < size; i++) std::cout << nums[i] << ' ';

	return 0; 
}