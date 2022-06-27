#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	char password[] = "pippo";

	if(argc != 2)
	{
		std::cout << "Password required.";
		return 0;
	}


	if(!strcmp(password, argv[1]))
		std::cout << "Access permitted \n";
	else
		std::cout << "Access denied \n";

	return 0;
}