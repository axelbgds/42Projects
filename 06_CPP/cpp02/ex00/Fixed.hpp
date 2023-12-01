/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:08:36 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/06 17:09:06 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Fixed {

    private :
        int fixedPointValue;
        static const int fractionalBits = 8;

    public :
        Fixed();
        Fixed(const Fixed& other);
        Fixed&  operator=(const Fixed& other); 
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(int const raw);

};
