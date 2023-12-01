/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:44:35 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:59:43 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    std::cout << "WrongCat constructor" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->_type = rhs.getType();
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << "WrongCat sound piouuuuuuu" << std::endl;
}
