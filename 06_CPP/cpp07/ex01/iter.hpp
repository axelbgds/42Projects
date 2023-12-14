/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:55:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/12 09:56:38 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *array, int length, void (*function)(T&)){
	for(int i = 0; i < length; i++)
		function(array[i]);};
		
template<typename T>
void	iter(T *array, int length, void (*function)(const T&)){
	for(int i = 0; i < length; i++)
		function(array[i]);};
		
#endif
