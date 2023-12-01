/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:46:50 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/13 15:22:45 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// 
Fixed::Fixed(const Fixed& other) {
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if(this != &other) {
        value = other.value;
    std::cout << "Copy assignement operator called" << std::endl;
    }
    return *this;
}

Fixed::Fixed(const int intValue) : value(intValue << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : value(roundf(floatValue *(1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt() const {
    return value >> fractionalBits;
}

float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    os << "Je m apppelle GROOT";
    return os;
}