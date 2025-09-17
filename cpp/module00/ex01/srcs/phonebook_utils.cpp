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

std::string truncate_imput(std::string imput)
{
    imput.erase(10);
    imput[9] = '.';
    return (imput);
}

std::string right_align(std::string imput, std::string::size_type len)
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



void    add_contact(phonebook *book, int *i)
{
    contact *cur;

    cur = book->contacts + *i;
    std::string temp_data;
    
    std::cout << "First name: ";
    temp_data = handle_imput(temp_data);
    cur->setFirstName(temp_data);

    std::cout << "Last name: ";
    temp_data = handle_imput(temp_data);
    cur->setLastName(temp_data);
    
    std::cout<< "Nickname: ";
    temp_data = handle_imput(temp_data);
    cur->setNickname(temp_data);
    
    std::cout<< "Phone Number: ";
    temp_data = handle_imput(temp_data);
    cur->setPhone(temp_data);
    
    std::cout<< "Darkest Secret: ";
    temp_data = handle_imput(temp_data);
    cur->setSecret(temp_data);
    
	std::cout << "Contact added correctly" << std::endl;
    cur->setAdded(true);
    *i += 1;
    if (*i == 8)
        *i = 0;
}

void    search_contact(phonebook *book)
{
    int         i;
    int         index;
    std::string contact_str;
    
    i = 0;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    while (i < 8 && book->contacts[i].isAdded())
    {
        std::cout << "         " << book->contacts[i].getIndex() << "|";
        std::cout << fill_data(book->contacts[i].getFirstName()) << "|";
        std::cout << fill_data(book->contacts[i].getLastName()) << "|";
        std::cout << fill_data(book->contacts[i].getNickname()) << std::endl;
        i++;
    }
    i = 0;
    std::cout << "Index: ";
    std::stringstream   ss(handle_imput(contact_str));
    ss >> index;
    if (index > 8)
        std::cout << "index out of range" << std::endl << "Index: ";
    while (i < 8 && book->contacts[i].isAdded())
    {
        if (index == book->contacts[i].getIndex())
        {
            std::cout << "index: " << book->contacts[i].getIndex() << std::endl;
            std::cout << "first name: " << book->contacts[i].getFirstName() << std::endl;
            std::cout << "last_name: " << book->contacts[i].getLastName() << std::endl;
            std::cout << "nickname: " << book->contacts[i].getNickname() << std::endl;
            std::cout << "phone: " << book->contacts[i].getPhone() << std::endl;
            std::cout << "darkest secret: " << book->contacts[i].getSecret() << std::endl;
        }
        i++;
    }
}

void    help_cmd(bool special)
{
    std::cout << "THESE ARE THE COMMANDS AVAILABLE FOR YOU: " << std::endl;
    std::cout << "ADD | SEARCH | EXIT | ";
    if (special == false)
        std::cout << "HELP" << std::endl;
    else if (special == true)
        std::cout << "HELP_PLS_IM_SO_SPECIAL" << std::endl;
}
