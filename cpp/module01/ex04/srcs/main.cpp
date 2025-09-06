#include <string>
#include <iostream>
#include <fstream>

int main(int arc, char **arv)
{
    if (arc == 4)
    {
        char* fname = arv[1];
        std::ifstream in(fname, std::ios_base::in);
        if (!in.is_open())
            std::cout << "error: Could not open the file" << std::endl;
        char* rname = arv[1]
        std::ofstream of(fname + replace, std::ios_base::out);
        if (!of.is_open())
            std::cout << "error: Could not create the replace file" << std::endl;
        in.close();
        of.close();
    }
    else
        std::cout << "error: wrong paramaters" << std::endl
                << "./ex04 filename s1 s2" << std::endl;
}