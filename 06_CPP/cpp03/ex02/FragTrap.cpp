/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:25:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/21 12:28:09 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDammage = 30; 
}

FragTrap::~FragTrap(void)
{
    std::cout << "destructor FragTrap called" << std::endl;
}
FragTrap::FragTrap(FragTrap const &src): ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDammage = rhs._attackDammage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap : please give me five guyss" << std::endl;
    
}