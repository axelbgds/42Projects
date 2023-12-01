/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:57 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:25:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
            ScavTrap(std::string name);
            ~ScavTrap(void);
            ScavTrap(ScavTrap const &src);
            ScavTrap& operator=(ScavTrap const &rhs);
            void guardGate();
};