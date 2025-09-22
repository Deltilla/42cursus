/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:44:11 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/22 19:45:32 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <Phonebook.hpp>

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

#endif