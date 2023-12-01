/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:59 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 15:10:58 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap" << this->_name << " Constructor called" << std::endl;
	_atkdmg = 20;
	_hitpoints = 100;
	_nrgpoints= 50;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAVTRAP destructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default SCAVTRAP constructor called" << std::endl;
	_atkdmg = 20;
	_hitpoints = 100;
	_nrgpoints= 50;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_atkdmg = rhs._atkdmg;
        this->_nrgpoints = rhs._nrgpoints;
        this->_hitpoints = rhs._hitpoints;
    }
    return *this;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitpoints && this->_nrgpoints)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing "
		<< _atkdmg << " points of damage! " << std::endl;
		this->_nrgpoints--;
	}
}

void ScavTrap::guardGate()
{
    std::cout  << this->_name << " ScavTrap has entered in Gate keeper mode." << std::endl;
}#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap D("Diamond");

	D.attack("ennemy");
	D.takeDamage(20);
	D.beRepaired(10);
	D.whoAmI();
	return (0);
}