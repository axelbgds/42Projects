/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:39:05 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 16:56:14 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(std::string name) : _myWeapon(NULL), _name(name) {
    std::cout << "constructor HumanB his name is " << _name << std::endl;
    std::cout << this->_name;
    std::cout << ":I have no weapon !" << std::endl << std::endl;
}

HumanB::~HumanB() {
    std::cout << "destructor HumanB" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) {
    this->_myWeapon = &weapon;
    std::cout << this->_name;
    std::cout << ": My new Weapon is a " << _myWeapon->Weapon::getType() << std::endl << std::endl;  
}

void    HumanB::Attack() {
    if (_myWeapon == NULL) {
        std::cout << "!!! Warning !!! ---- ";
        std::cout << this->_name << "punch attacks" << std::endl << std::endl; 
    }
    else {
        std::cout << "!!! Warning !!! --- ";
        std::cout << this->_name << " attack with his " << _myWeapon->Weapon::getType() << std::endl << std::endl;
    }
}