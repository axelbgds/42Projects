/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:25:12 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/21 12:27:48 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
            FragTrap(std::string name);
            ~FragTrap(void);
            FragTrap(FragTrap const &src);
            FragTrap& operator=(FragTrap const &rhs);
            void highFivesGuys(void);
};