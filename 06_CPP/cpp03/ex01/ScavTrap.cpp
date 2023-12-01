/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:59 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:24:47 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_name = "Default";
	this->_hitpoints = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hitpoints = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	this->_name = src._name;
	this->_hitpoints = src._hitpoints;
	this->_energy = src._energy;
	this->_damage = src._damage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
	}

	std::cout << "ScavTrap assignment operator called" << std::endl;

	return *this;
}

void ScavTrap::attack(std::string const &target) {

	if (not this->_energy) {
		std::cout << "ScavTrap " << this->_name << " has no more energy points and is dead!" << std::endl;
		return ;
	}

	this->_energy--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing him " << this->_damage << " damage points!" << std::endl;

	if (not this->_energy)
		std::cout << "ScavTrap " << this->_name << " has no more energy points and is dead!" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " has now " << this->_energy << " energy points" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}