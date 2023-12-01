/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:25:06 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
    public :
            ClapTrap(void);
            ClapTrap(std::string name);
            ClapTrap(ClapTrap const &src);
            ClapTrap& operator=(ClapTrap const &rhs);
            ~ClapTrap(void);
            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);

    protected :
            std::string _name;
            unsigned int _hitPoints;
            unsigned int _attackDammage;
            unsigned int _energyPoints;
};