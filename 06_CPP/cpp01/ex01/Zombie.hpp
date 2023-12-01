/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:33:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 12:34:53 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie {
    private :
        std::string _name;

    public :
        Zombie(void);
        ~Zombie();
        void    announce(void);
        void    setname(std::string, int i);
};

Zombie* zombieHorde(int N, std::string name);