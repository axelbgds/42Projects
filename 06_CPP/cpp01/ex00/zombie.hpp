/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:07 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/31 16:26:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie {
    private :
        std::string _name;

    public :
        Zombie(std::string name);
        ~Zombie();
        void announce();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
