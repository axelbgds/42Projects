/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/31 16:26:59 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main() {
    Zombie* dynamicZombie = newZombie("Dynamic Zombie");
    dynamicZombie->announce();
    randomChump("Stack Zombie");
    delete dynamicZombie;
    return 0;
}