#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

void	replace_word(std::string *line, char* s1, char* s2)
{
	std::istringstream ss(*line);
	std::string word;
	std::string new_line;
	while (ss >> word)
	{
		if (word.compare("\n") != 0)
			new_line += " ";
		if (word.compare(s1) == 0)
			word = s2;
		new_line += word;
	}
	*line = new_line;
}

int main(int arc, char **arv)
{
	std::string line;

    if (arc == 4)
    {
		std::string fname = arv[1];
		std::string ofname = fname + ".replace";
        std::ifstream in(fname.c_str(), std::ios_base::in);
        if (!in.is_open())
            std::cout << "error: Could not open the file" << std::endl;
		std::ofstream of(ofname.c_str(), std::ios_base::out);
		if (!of.is_open())
        std::cout << "error: Could not create the replace file" << std::endl;
		while (getline(in, line))
		{
			replace_word(&line, arv[2], arv[3]);
			of << line << std::endl;
		}
        in.close();
        of.close();
    }
    else
        std::cout << "error: wrong paramaters" << std::endl
                << "./ex04 filename s1 s2" << std::endl;
}