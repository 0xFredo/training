#include <iostream>

//iterate over array,
//for each element, look over the array
//check for other element except itself

int main()
{
	int size = 10;
	int array[] = {3, 2, 4, 3, 5, 2, 6, 9, 4, 8};

	for(int i = 0; i < size; i++)
		for(int count = i+1; count < size; count++)
			if(array[i] == array[count])
				std::cout << array[i] << " at position " << count << "\n";
}