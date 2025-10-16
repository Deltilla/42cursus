/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:36:31 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/16 20:06:13 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <Data.hpp>

class Serializer {

    private:

        Serializer();
        Serializer( const Serializer& );
        Serializer& operator=( const Serializer& );
        ~Serializer();

    public:
	
        static uintptr_t    serialize( Data* ptr );
        static Data*        deserialize( uintptr_t raw );

};

#endif