/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:33:57 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 12:26:35 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
        horde[i].setname(name, i + 1);
    return horde;
}