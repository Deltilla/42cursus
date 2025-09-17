/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:35:32 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/10 19:12:14 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phonebook.hpp>
#include <stdio.h>
#include <cctype>

std::string handle_imput(std::string data)
{
    std::cin >> data;
    if (data.empty())
        exit(EXIT_FAILURE);
    else
    {
        for (size_t i = 0; i < data.length(); i++)
            if (!std::isprint(data[i]))
            {
                std::cout << "It seems like you are very special, please enter a valid imput" << std::endl;
                return (handle_imput(data));
            }
    }
    return (data);
}

int handle_commands(phonebook *book, std::string username, std::string cmd, int *i, bool special)
{
    (void)username;
    if (!cmd.compare("ADD"))
        return(add_contact(book, i), 1);
    else if (!cmd.compare("SEARCH"))
        return(search_contact(book), 1);
    else if (!cmd.compare("HELP") && !special)
        return(help_cmd(special), 1);
    else if (!cmd.compare("HELP_PLS_IM_SO_SPECIAL"))
        return(help_cmd(true), 1);
    else if (!cmd.compare("EXIT"))
        exit(EXIT_SUCCESS);
    return (0);
}

void    init_book(phonebook *book, std::string username)
{
    int i;

    i = 0;
    while (++i <= 8)
    {
        book->contacts[i - 1].setIndex(i);
        book->contacts[i - 1].setAdded(false);
    }
    std::cout << "Please enter your username: " << std::endl;
    std::cout << "username: ";
    username = handle_imput(username);
    std::cout << "Your username is: Douchebag, it is correct? If not try again" << std::endl;
    std::cout << "username: ";
    username = handle_imput(username);
    std::cout << "Your username is: " << username << ", it is correct?" << std::endl;
    std::cout << "Write YES or NO: ";
    username = handle_imput(username);
    std::cout << "Hi Douchebag, welcome to your AwesomeSuperSpecialPromptPhonebook aka ASSPP!!" << std::endl;
    username = "Douchebag";
    std::cout << "Enter any command, if you dont know them you can write: HELP" << std::endl;
}

int main()
{
    phonebook   book;
    std::string username;
    std::string command;
    int         i;
    bool        special;
    
    init_book(&book, username);
    i = 0;
    special = false;
    while (1)
    {
        std::cout << "Douchebag's ASSPP: ";
        command = handle_imput(command);
        if (!handle_commands(&book, username, command, &i, special))
        {
            std::cout << "It seems like you are very special, please enter a valid command, if you dont know them you can write:" <<  std::endl;
            std::cout <<"HELP_PLS_IM_SO_SPECIAL" << std::endl;
            special = true;
        }
        command.clear();
    }
}
