/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:43:54 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/22 19:45:38 by analba-s         ###   ########.fr       */
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
# include <Contact.hpp>

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