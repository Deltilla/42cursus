/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/11/10 19:38:04 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

//template <typename T, typename F>
//void iter(T *arr, const size_t len, F func) {
//    for (size_t i = 0; i < len; i++) {
//		func(arr[i]);
//	}
//}

template <typename T, typename F, size_t N>
void iter(T(&arr)[N], const size_t len, F func) {
	size_t size = len;
	if (len > N)
		size = N;
    for (size_t i = 0; i < size; i++) {
		func(arr[i]);
	}
}

#endif