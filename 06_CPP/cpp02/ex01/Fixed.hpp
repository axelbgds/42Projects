/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:41:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/13 15:11:06 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
    private:
        int value;
        static const int fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        
        Fixed(const int intValue);
        Fixed(const float floatValue);
        int toInt() const;
        float toFloat() const;

        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

};