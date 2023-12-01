/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:01 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:24:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitpoints(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hitpoints(src._hitpoints), _energy(src._energy), _damage(src._damage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
	}

	std::cout << "ClapTrap assignment operator called" << std::endl;

	return *this;
}

void ClapTrap::attack(std::string const &target) {

	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " has no more energy points and is dead!" << std::endl;
		return ;
	}

	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing him " << this->_damage << " damage points!" << std::endl;

	if (this->_energy == 0)
		std::cout << "ClapTrap " << this->_name << " has no more energy points and is dead!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has now " << this->_energy << " energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (not this->_hitpoints) {
		std::cout << "ClapTrap " << this->_name << " is already dead and cannot take anymore damages" << std::endl;
		return ;
	}
	
	if (amount >= this->_hitpoints) {
		this->_hitpoints = 0;
		std::cout << "ClapTrap " << this->_name << " has been killed!" << std::endl;
	}
	else {
		this->_hitpoints -= amount;
		std::cout << "ClapTrap " << this->_name << " took " << amount << " damage points and has now " << this->_hitpoints << " hit points" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hitpoints == 10) {
		std::cout << "ClapTrap " << this->_name << " does not need any repairs" << std::endl;
		return ;
	}

	if (not this->_hitpoints) {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
		return ;
	}

	if (not this->_energy) {
		std::cout << "ClapTrap " << this->_name << " has no more energy points to repair itself" << std::endl;
		return ;
	}

	if (amount < 10 - this->_hitpoints) {
		this->_hitpoints += amount;
		this->_energy--;
		std::cout << "ClapTrap " << this->_name << " got repaired and now has " << this->_hitpoints << " hit points " << std::endl;
	}	
	else {
		this->_hitpoints = 10;
		std::cout << "ClapTrap " << this->_name << " got repaired and is now fully healed and has " << this->_hitpoints << " hit points " << std::endl;
	}
}