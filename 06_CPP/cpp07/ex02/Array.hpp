/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:55:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/12 09:58:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	public:
		Array();	
		Array&	operator=(Array const &src);
		Array<T>(Array<T> & src);
		Array(unsigned int i);
		~Array();
		T&		operator[](int index);
		unsigned int	size();
	private:
		T	*_tab;
		unsigned int	_size;
};

template<typename T>
Array<T>::Array(): _size(0){
	_tab = new T[0];}

template<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &src)
{
	_tab = new T[src._size];
	for (int i = 0; i < src._size; i++)
	{
		_tab[i] = src._tab[i];
	}
	_size = src._size;
	return (*this);
}

template<typename T>
Array<T>::Array(Array<T> & src){
	*this = src;}


template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	_tab = new T[size];
		for (int i = 0; i < size; i++)
			_tab[i] = size;
}

template<typename T>
Array<T>::~Array(){
	delete[] _tab;}

template<typename T>
T&			Array<T>::operator[](int index)
{
	if (index < _size)
		return (this->_tab[index]);
	else
		throw (std::exception());
}

template<typename T>
unsigned int	Array<T>::size(){
	return(_size);}
#endif
