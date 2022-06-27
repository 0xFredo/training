/*
	Project 3-1

	Help system.
*/

#include <iostream>

int main()
{
	char choice;

	for( ; ; )
	{	
		do
		{
			std::cout << "Help on:\n";
			std::cout << "	1. if\n";
			std::cout << "	2. switch\n";
			std::cout << "	3. for\n";
			std::cout << "	4. while\n";
			std::cout << "	5. do-while\n";
			std::cout << "	6. break\n";
			std::cout << "	7. continue\n";
			std::cout << "	8. goto\n";
			std::cout << "Choose one (q to quit): ";
			std::cin >> choice;
		} while( choice < '1' || choice > '8' && choice != 'q');

		if(choice == 'q') break;
		std::cout << "\n\n";

		switch(choice)
		{
			case '1':
				std::cout << "The if:\n\n";
				std::cout << "if(condition) statement;\n";
				std::cout << "else statement;\n";
				break;
			case '2':
				std::cout << "The switch:\n\n";
				std::cout << "switch(expression):\n";
				std::cout << "{\n";
				std::cout << " statement sequence\n";
				std::cout << " break;\n";
				std::cout << " // ...\n";
				std::cout << "}\n";
				break;
			case '3':
				std::cout << "The for:\n\n";
				std::cout << "for(init; condition; increment);";
				std::cout << " statement\n";
				break;
			case '4':
				std::cout << "The while:\n\n";
				std::cout << "while(condition) statement;\n";
				break;
			case '5':
				std::cout << "The do-while:\n\n";
				std::cout << "do\n";
				std::cout << "{\n";
				std::cout << " statement;\n";
				std::cout << "} while(condition);\n";
				break;
			case '6':
				std::cout << "The break:\n\n";
				std::cout << "break;\n";
				break;
			case '7':
				std::cout << "The continue:\n\n";
				std::cout << "continue;\n";
				break;
			case '8':
				std::cout << "The goto:\n\n";
				std::cout << "goto label;\n";
				break;
		}
		std::cout << "\n";
	}

	return 0;
}