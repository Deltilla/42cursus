/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:43:54 by analba-s          #+#    #+#             */
/*   Updated: 2025/07/21 17:33:30 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cctype>
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <stdlib.h>
# include <stdbool.h>

class   contact
{
	// Atributos
    private:
        int         index;
        bool        added;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string secret;

    public:
        // Métodos para acceder a datos (getters)
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhone() const;
        std::string getSecret() const;
        int         getIndex() const;
        bool        isAdded() const;

        // Métodos para editar datos (setters)
        void setFirstName(const std::string& name);
        void setLastName(const std::string& name);
        void setNickname(const std::string& name);
        void setPhone(const std::string& number);
        void setSecret(const std::string& secret_note);
        void setIndex(int idx);
        void setAdded(bool status);
};

class   phonebook
{
    public:
        contact contacts[8];
        int     oldest_index;
};

std::string	handle_imput(std::string data);
void		add_contact(phonebook *book, int *i);
void		search_contact(phonebook *book);
void		help_cmd(bool special);

#endif