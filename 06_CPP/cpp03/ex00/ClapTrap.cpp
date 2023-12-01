/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:28:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:24:26 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energy(10), _attack(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energy(10), _attack(0) {
    std::cout << "Claptrap " << this->_name << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hitPoints(src._hitPoints), _energy(src._energy), _attack(src._attack) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energy = rhs._energy;
        this->_attack = rhs._attack;
    }
    std::cout << "ClapTrap assignement operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (not this->_energy) {
        std::cout << "ClapTrap " << this->_name << " has no more energy points and is dead!" << std::endl;
        return ;
    }
    this->_energy--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing him " << this->_attack << " damage points!" << std::endl;

    if (not this->_energy)
        std::cout << "ClapTrap " << this->_name << " has no more energy points and is dead!" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " has now " << this->_energy << " energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (not this->_hitPoints) {
        std::cout << "ClapTrap " << this->_name << " is already dead and cannot take anymore damages" << std::endl;
        return;
    }

    if (amount <= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " has been killed!" << std::endl;
    }
    else {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " damage points and has now " << this->_hitPoints << " hit points" << std::endl; 
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 10) {
        std::cout << "ClapTrap " << this->_name << " does not need any repairs" << std::endl;
        return ; 
    }

    if(not this->_hitPoints) {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
        return ;
    }

    if(not this->_energy) {
        std::cout << "ClapTrap " << this->_name << " has no more energy points to repair itself" << std::endl;

    }

    if(amount < 10 - this->_hitPoints) {
        this->_hitPoints += amount;
        this->_energy--;
        std::cout << "ClapTrap " << this->_name << " got repaired and now has" << this->_hitPoints << " hit points " << std::endl;
    }
    else {
        std::cout << "ClapTrap " << this->_name << " got repaired and is now fully healed and has" << this->_hitPoints << " hit points " << std::endl;

    }
}

