/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:01 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 15:10:02 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitpoints(10), _nrgpoints(10), _atkdmg(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hitpoints(10), _nrgpoints(10), _atkdmg(0)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_nrgpoints = rhs._nrgpoints;
		this->_atkdmg = rhs._atkdmg;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitpoints && this->_nrgpoints)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing "
		<< _atkdmg << " points of damage! " << std::endl;
		this->_nrgpoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage from the ennemie"
	<< std::endl;
	this->_hitpoints -= amount;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints && this->_nrgpoints)
	{
		std::cout << "ClapTrap " << this->_name << " heal " << amount
		<< " lifepoint " << std::endl;
		this->_nrgpoints--;
	}
}