/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weappon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:37:21 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 16:36:58 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << "constructor Weapon : " << type << std::endl;
}

Weapon::~Weapon() {
    std::cout << "destructor Weapon : " << this->_type << std::endl;
}

const   std::string &Weapon::getType()const {
    return this->_type;
}

void    Weapon::setType(std::string type) {
    std::cout << this->_type << " now is a \" ";
    this->_type = type;
    std::cout << this->_type << "\"" << std::endl << std::endl;
}