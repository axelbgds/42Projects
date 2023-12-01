/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:30:36 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 13:06:22 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    DiamondTrap    a1("FragTrap1");
    DiamondTrap    a2(a1);
    DiamondTrap    a3(void);

    a1.attack("ennemy");
    a1.takeDamage(30);
    a1.beRepaired(10);
    a1.highFivesGuys();
    return(0);
}