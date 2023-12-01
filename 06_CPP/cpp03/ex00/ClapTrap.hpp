/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:28:32 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:24:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iostream>

class ClapTrap {

    private:
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energy;
        unsigned int    _attack;

    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap(void);

        ClapTrap &operator=(ClapTrap const &rhs);
               
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        std::string     getName(void) const;
        unsigned int    getHitPoint(void) const;
        unsigned int    getEnergy(void) const;
        unsigned int    getAttack(void) const;

};
