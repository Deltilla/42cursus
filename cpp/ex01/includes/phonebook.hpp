/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:43:54 by analba-s          #+#    #+#             */
/*   Updated: 2025/07/11 14:28:21 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cctype>
# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdbool.h>

class	contact
{
	public:
		int			index;
		bool		added;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
};

class	phonebook
{
	public:
		contact	contacts[8];
		int		oldest_index;
};

std::string	handle_imput(std::string data);
void		add_contact(phonebook *book, int *i);
void		search_contact(phonebook *book);
void		help_cmd(bool special);

#endif