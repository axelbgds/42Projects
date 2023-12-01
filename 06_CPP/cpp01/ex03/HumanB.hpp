/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:39:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 16:48:54 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanB {

    private :
        Weapon *_myWeapon;
        std::string _name;

    public :
        HumanB(std::string name);
        ~HumanB();

        void    setWeapon(Weapon &weapon);
        void    Attack(void);

};