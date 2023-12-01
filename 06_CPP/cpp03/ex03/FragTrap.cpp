/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:25:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 15:10:08 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	_hitpoints = 100;
	_nrgpoints = 100;
	_atkdmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	_hitpoints = 100;
	_nrgpoints = 100;
	_atkdmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_atkdmg = rhs._atkdmg;
        this->_nrgpoints = rhs._nrgpoints;
        this->_hitpoints = rhs._hitpoints;
    }
    return *this;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap ask for a high five" << std::endl;
}