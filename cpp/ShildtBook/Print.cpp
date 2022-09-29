//Project 6-1 | Overloaded print and println | Mastery check 6-8
#include <iostream>

void print(bool b, int indent = 0);
void print(int i, int indent = 0);
void print(long l, int indent = 0);
void print(char ch, int indent = 0);
void print(char *str, int indent = 0);
void print(double d, int indent = 0);

void println(bool b, int indent = 0);
void println(int i, int indent = 0);
void println(long l, int indent = 0);
void println(char ch, int indent = 0);
void println(char *str, int indent = 0);
void println(double d, int indent = 0);

int main()
{
	println(true, 10);
	println(10, 20);
	println("This is a test");
	println('X');
	println(99L);
	println(123.23);

	print("Here are some values: ");
	print(' ');
	print(88);
	print(' ');
	print(100000L);
	print(' ');
	print(100.01);

	println(" Done!");

	return 0;
}

void print(bool b, int indent)
{
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	if(b) std::cout << "true";
	else std::cout << "false";
}

void print(int i, int indent)
{
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << i;
}

void print(long l, int indent)
{
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << l;
}

void print(char ch, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << ch;
}

void print(char *str, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << str;
}

void print(double d, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << d;
}

void println(bool b, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	if(b) std::cout << "true\n";
	else std::cout << "false\n";
}

void println(int i, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << i << "\n";
}

void println(long l, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << l << "\n";
}

void println(char ch, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << ch << "\n";
}

void println(char *str, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << str << "\n";
}

void println(double d, int indent)
{	
	if(indent)
		for(int i = 0; i < indent; i++) std::cout << ' ';

	std::cout << d << "\n";
}