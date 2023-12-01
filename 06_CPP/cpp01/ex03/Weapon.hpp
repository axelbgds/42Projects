/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:37:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 16:47:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon {

    private :
        std::string _type;

    public :
        Weapon(std::string type);
        ~Weapon();

        const std::string   &getType() const;
        void                setType(std::string type);

};