/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:09:19 by analba-s          #+#    #+#             */
/*   Updated: 2025/07/21 18:05:55 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phonebook.hpp>
#include <stdio.h>

std::string	truncate_imput(std::string imput)
{
	imput.erase(10);
	imput[9] = '.';
	return (imput);
}

std::string	right_align(std::string imput, std::string::size_type len)
{
	std::string spaces(10 - len, ' ');
	return (spaces + imput);
}

std::string fill_data(std::string data)
{
	std::string	imput;
	std::string::size_type len;

	imput = handle_imput(imput);
	len = imput.size();
	if (len < 10)
		data = right_align(imput, len);
	else if (len > 10)
		data = truncate_imput(imput);
	return (data);
}

void	add_contact(phonebook *book, int *i)
{
	contact *cur;

	cur = book->contacts + *i;
	std::cout << "First name: ";
	cur->first_name = fill_data(cur->first_name);
	std::cout << "Last name: ";
	cur->last_name = fill_data(cur->last_name);
	std::cout<< "Nickname: ";
	cur->nickname = fill_data(cur->nickname);
	std::cout<< "Phone Number: ";
	cur->phone = fill_data(cur->phone);
	std::cout<< "Darkest Secret: ";
	cur->secret = fill_data(cur->secret);
	cur->added = true;
	*i += 1;
	if (*i == 8)
		*i = 0;
}

void	search_contact(phonebook *book)
{
	int			i;
	int			index;
	std::string			contact;
	
	i = 0;
	while (i < 8 && book->contacts[i].added)
	{
		std::cout << book->contacts[i].index << "|";
		std::cout << book->contacts[i].first_name << "|";
		std::cout << book->contacts[i].last_name << "|";
		std::cout << book->contacts[i].nickname << std::endl;
		i++;
	}
	i = 0;
	std::cout << "Douchebag's ASSPP: ";
	std::stringstream	ss(handle_imput(contact));
	ss >> index;
	while (i < 8 && book->contacts[i].added)
	{
		if (index == book->contacts[i].index)
		{
			std::cout << book->contacts[i].index << std::endl;
			std::cout << book->contacts[i].first_name << std::endl;
			std::cout << book->contacts[i].last_name << std::endl;
			std::cout << book->contacts[i].nickname << std::endl;
			std::cout << book->contacts[i].phone << std::endl;
			std::cout << book->contacts[i].secret << std::endl;
		}
		i++;
	}
}

void	help_cmd(bool special)
{
	std::cout << "THESE ARE THE COMMANDS AVAILABLE FOR YOU: " << std::endl;
	std::cout << "ADD | SEARCH | EXIT | ";
	if (special == false)
		std::cout << "HELP" << std::endl;
	else if (special == true)
		std::cout << "HELP_PLS_IM_SO_SPECIAL" << std::endl;
}
