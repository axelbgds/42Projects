/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:41:39 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/13 16:08:48 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class Fixed {
private:
    int value;
    static const int fractionalBits;

public:
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed& other);
    ~Fixed();

    float toFloat() const;
    int toInt() const;

    Fixed& operator=(const Fixed& other);

    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();       // Pre-increment
    Fixed operator++(int);     // Post-increment
    Fixed& operator--();       // Pre-decrement
    Fixed operator--(int);     // Post-decrement

    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};