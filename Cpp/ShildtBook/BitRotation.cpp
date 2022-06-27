// Project 7-1 | Mastery 7-9
#include <iostream>

unsigned char lrotate(unsigned char val, int n);
unsigned char rrotate(unsigned char val, int n);
void show_binary(unsigned int u);

int main()
{
	char message[] = "test";
	int bitRotationKey = 5;

	std::cout << "Original message: " << message << "\n";

	std::cout << "Binary: \n";
	for(int i = 0; message[i]; i++) show_binary(message[i]);

	for(int i = 0; message[i]; i++)
	{
		message[i] = lrotate(message[i], bitRotationKey);
	}
	std::cout << "Encoded message: " << message << "\n";
	std::cout << "Binary: \n";
	for(int i = 0; message[i]; i++) show_binary(message[i]);

	for(int i = 0; message[i]; i++)
	{
		message[i] = rrotate(message[i], bitRotationKey);
	}
	std::cout << "Decoded message: " << message << "\n";
	std::cout << "Binary: \n";
	for(int i = 0; message[i]; i++) show_binary(message[i]);

	return 0;
}

unsigned char lrotate(unsigned char val, int n)
{
	unsigned int t;
	t = val;

	for(int i = 0; i < n; i++)
	{
		t = t << 1;

		//If a bit shifts out, it will be in bit 8 of the integer t. If this is the case, put that bit on the right side
		if(t & 256)
			t = t | 1;
	}

	return t;
}

unsigned char rrotate(unsigned char val, int n)
{
	unsigned int t;
	t = val;

	t = t << 8;

	for(int i = 0; i < n; i++)
	{
		t = t >> 1;

		//If a bit shifts out, it will be in bit 7 of the integer t. If this is the case, put that bit on the left side
		if(t & 128)
			t = t | 32768;
	}

	t = t >> 8;
	return t;
}

void show_binary(unsigned int u)
{
	int byteNum = sizeof(u);
	u = u << ((byteNum - 1) * 8);
	for(int i = 0; i < byteNum; i++)
	{
		for(int t = 128; t > 0; t = t/2)
		{
			if(u & t) std::cout << "1 ";
			else std::cout << "0 ";
		}
		u = u >> 8;
		std::cout << " | ";	
	}
	std::cout << "\n";	
}