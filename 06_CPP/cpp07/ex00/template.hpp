/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:00:02 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/12 09:56:30 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>

template< typename T>
void	swap(T& a, T& b)
{
	T	temp = a;
	a = b;
	b = temp;
};

template< typename T>
const T		min(T a, T b){ 
	return (a<=b ? a : b);};

template< typename T>
const T		max(T a, T b){ 
	return (a>=b ? a : b);};

#endif
