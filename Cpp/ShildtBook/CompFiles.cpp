//Project 11-1

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    register int i;
    unsigned char buf1[1024], buf2[1024];

    if(argc != 3)
    {
        std::cout << "Usage: compare files <file1> <file2>\n";
        return 1;
    }

    std::ifstream f1(argv[1], std::ios::in | std::ios::binary);
    if(!f1)
    {
        std::cout << "Cannot open first file\n";
        return 1;
    }

    std::ifstream f2(argv[2], std::ios::in | std::ios::binary);
    if(!f2)
    {
        std::cout << "Cannot open second file\n";
    }

    std::cout << "Compare files...\n";

    do
    {
        f1.read((char *)buf1, sizeof buf1);
        f2.read((char *)buf2, sizeof buf2);

        if(f1.gcount() != f2.gcount())
        {
            std::cout << "Files are of differing sizes.\n";
            f1.close();
            f2.close();
            return 0;
        }

        for(i = 0; i < f1.gcount(); i++)
        {
            if(buf1[i] != buf2[i])
            {
                std::cout << "Files differ.\n";
                f1.close();
                f2.close();
                return 0;
            }
        }
    } while (!f1.eof() && !f2.eof());

    std::cout << "Files are the same!\n";
    f1.close();
    f2.close();

    return 0;
    

}