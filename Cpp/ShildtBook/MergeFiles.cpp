//Mastery check 11-13
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{   

    char transportCh;

    if(argc != 4)
    {
        std::cout << "Bad arguments.\n";
        return 0;
    }

    std::ifstream inFile1(argv[1], std::ios::in | std::ios::binary);
    if(!inFile1)
    {
        std::cout << "Can't open first input file.\n";
        return 0;
    }

    std::ifstream inFile2(argv[2], std::ios::in | std::ios::binary);
    if(!inFile2)
    {
        std::cout << "Can't open second input file.\n";
        return 0;
    }

    std::ofstream outFile(argv[3], std::ios::out | std::ios::binary);
    if(!outFile)
    {
        std::cout << "Can't open output file.\n";
        return 0;
    }

    while(!inFile1.eof())
    {
        inFile1.get(transportCh);
        outFile.put(transportCh);
    }

    while(!inFile2.eof())
    {
        inFile2.get(transportCh);
        outFile.put(transportCh);
    }

    inFile1.close();
    inFile2.close();
    outFile.close();

    return 0;
}