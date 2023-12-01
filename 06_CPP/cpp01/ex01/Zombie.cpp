/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:33:16 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 12:45:35 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie::Zombie(void) {
    return;
}

Zombie::~Zombie(void) {
    return;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

void Zombie::setname(std::string name, int i) {
    std::stringstream ss;
    ss << i;
    _name = name + ss.str();
    Zombie::announce();
    return;
}
