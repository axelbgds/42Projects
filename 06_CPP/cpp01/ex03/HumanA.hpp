/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:37:35 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 16:47:35 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanA {

    private :
        const Weapon &_myWeapon;
        std::string _name;

    public :
        HumanA(Weapon &myWeapon, std::string name);
        ~HumanA();

        void    Attack(void);

};