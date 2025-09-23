/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:13:14 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/23 19:21:58 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


void	handle_line(std::string *line, char* s1, char* s2)
{
	std::istringstream ss(*line);
	std::string curWord;
	std::string nextWord;
	std::string new_line;
	ss >> curWord;
	while (curWord != "\n" && !ss.eof()) {
		ss >> nextWord;
		if (curWord.compare(s1) == 0)
			curWord = s2;
		if (!nextWord.empty() && nextWord.compare("\n") != 0)
			curWord += " ";
		new_line += curWord;
		curWord = nextWord;
	}
	if (curWord.compare(s1) == 0)
		curWord = s2;
	new_line += curWord;
	*line = new_line;
}

int main(int arc, char **arv)
{
	std::string line;
	int i;

	i = 0;
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
			if (i == 1)
				of << std::endl;
			handle_line(&line, arv[2], arv[3]);
			of << line;
			i = 1;
		}
        in.close();
        of.close();
    }
    else
        std::cout << "error: wrong paramaters" << std::endl
                << "./ex04 filename s1 s2" << std::endl;
}