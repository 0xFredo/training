//Mastery check 11-12
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    char ch;

    if(argc != 3)
    {
        std::cout << "Wrong arguments\n";
        return 0;
    }

    std::ifstream inFile(argv[1], std::ios::in | std::ios::binary);
    if(!inFile)
    {
        std::cout << "Cannot open input file.\n";
        return 0;
    }

    std::ofstream outFile(argv[2], std::ios::out | std::ios::binary);
    if(!outFile)
    {
        std::cout << "Cannot open output file.\n";
        return 0;
    }

    while(!inFile.eof())
    {
        inFile.get(ch);
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();

    return 0;   
}