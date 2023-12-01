/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:05:35 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 15:10:04 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_nrgpoints = ScavTrap::_nrgpoints;
	this->_atkdmg = FragTrap::_atkdmg;
	this->_name = name;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_atkdmg = rhs._atkdmg;
        this->_nrgpoints = rhs._nrgpoints;
        this->_hitpoints = rhs._hitpoints;
    }
    return *this;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(src), ScavTrap(src), FragTrap(src) 
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << this->_name << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}