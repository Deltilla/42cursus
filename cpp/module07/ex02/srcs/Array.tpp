/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:36:08 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/21 17:08:49 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

template<typename T>
Array<T>::Array( void )
{
	std::cout << "Array default constructor called" << std::endl;
	this->_array = NULL;
	this->_size = 0;
}

template<typename T>
Array<T>::Array( unsigned int n )
{
	std::cout << "Array size(n) constructor called" << std::endl;
	this->_array = (n ? new T[n]() : NULL);
	this->_size = static_cast<size_t>(n);
}

template<typename T>
Array<T>::Array( const Array& copy )
{
	std::cout << "Array copy constructor called" << std::endl;
	this->_array = NULL;
	this->_size = copy._size;
	if (this->_size > 0) {
		this->_array = new T(this->_size);
		for (size_t i = 0; i < this->_size; ++i)
			this->_array[i] = copy._array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=( const Array& copy )
{
	if (this == &copy)
        return *this;

    T* new_array = NULL;
    if (copy._size > 0)
    {
        new_array = new T[copy._size];
        for (size_t i = 0; i < copy._size; ++i)
            new_array[i] = copy._array[i];
    }

    delete [] _array;
    _array = new_array;
    _size = copy._size;

    return *this;
}

template<typename T>
T& Array<T>::operator[]( size_t i )
{
	if (i >= this->_size)
		throw std::out_of_range("Array::operator[] index out of range");
	return (this->_array[i]);
}

template <typename T>
const T& Array<T>::operator[](size_t i) const
{
    if (i >= _size)
        throw std::out_of_range("Array::operator[] index out of range");
    return this->_array[i];
}

template<typename T>
size_t Array<T>::size( void )
{
	return ( this->_size );
}

template<typename T>
Array<T>::~Array( void ) 
{
	std::cout << "Array destructor called" << std::endl;
	delete []this->_array;
}