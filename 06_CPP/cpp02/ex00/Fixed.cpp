/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:08:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/15 10:39:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.fixedPointValue;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other) {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}
int Fixed::getRawBits() const {
    std::cout << "getRawbits member function called" << std::endl;
    return this->fixedPointValue;
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member functions called" << std::endl;
    this->fixedPointValue = raw;
}
