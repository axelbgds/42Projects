/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:37:12 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 16:42:47 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(Weapon &myWeapon, std::string name) : _myWeapon(myWeapon), _name(name) {
    std::cout << "constructor HumanA His name is " << _name << std::endl;
    std::cout << this->_name;
    std::cout << " : My weapon is a " << myWeapon.getType() << std::endl << std::endl;
}

HumanA::~HumanA() {
    std::cout << "destructor HumanA" << std::endl;
}

void    HumanA::Attack() {
    std::cout << "!!! Warning !!!! -----";
    std::cout << this->_name << " attacks with this " << _myWeapon.Weapon::getType() << std::endl;
}
