/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:09:19 by analba-s          #+#    #+#             */
/*   Updated: 2025/07/28 12:50:09 by analba-s         ###   ########.fr       */
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
	std::string::size_type len;
	
	len = data.size();
	if (len < 10)
		data = right_align(data, len);
	else if (len > 10)
		data = truncate_imput(data);
	return (data);
}



void	add_contact(phonebook *book, int *i)
{
	contact *cur;

	cur = book->contacts + *i;
	std::cout << "First name: ";
	cur->first_name = handle_imput(cur->first_name);
	std::cout << "Last name: ";
	cur->last_name = handle_imput(cur->last_name);
	std::cout<< "Nickname: ";
	cur->nickname = handle_imput(cur->nickname);
	std::cout<< "Phone Number: ";
	cur->phone = handle_imput(cur->phone);
	std::cout<< "Darkest Secret: ";
	cur->secret = handle_imput(cur->secret);
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
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < 8 && book->contacts[i].added)
	{
		std::cout << "         " << book->contacts[i].index << "|";
		std::cout << fill_data(book->contacts[i].first_name) << "|";
		std::cout << fill_data(book->contacts[i].last_name) << "|";
		std::cout << fill_data(book->contacts[i].nickname) << std::endl;
		i++;
	}
	i = 0;
	std::cout << "Index: ";
	std::stringstream	ss(handle_imput(contact));
	ss >> index;
	if (index > 8)
		std::cout << "index out of range" << std::endl << "Index: ";
	while (i < 8 && book->contacts[i].added)
	{
		if (index == book->contacts[i].index)
		{
			std::cout << "index: " << book->contacts[i].index << std::endl;
			std::cout << "first name: " << book->contacts[i].first_name << std::endl;
			std::cout << "last_name: " << book->contacts[i].last_name << std::endl;
			std::cout << "nickname: " << book->contacts[i].nickname << std::endl;
			std::cout << "phone: " << book->contacts[i].phone << std::endl;
			std::cout << "darkest secret: " << book->contacts[i].secret << std::endl;
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
