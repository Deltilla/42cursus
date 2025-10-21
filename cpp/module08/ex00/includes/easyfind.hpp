/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/21 17:53:20 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind( T &cont, int n ) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw std::runtime_error("easyfind: value not found");
	return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T &cont, int n) {
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), n);
    if (it == cont.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}

#endif