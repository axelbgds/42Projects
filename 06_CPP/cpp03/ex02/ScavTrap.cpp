/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:59 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:25:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap Constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDammage = 20;
}
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap::ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDammage = rhs._attackDammage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap has entered Gate Keeper mode" << std::endl;
}