/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:33:04 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 15:11:13 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int i;
    std::string name;

    std::cout << "Hello it's special day, you can create a special Zombiee ZEUBYY !!!" << std::endl;
    std::cout << "Tell me how many you want to create : ";;
    std::cin >> i;
    std::cout << "Perfect, now share me a name : ";
    std::cin >> name;
    Zombie *horde = zombieHorde((int)i, name);
    delete[] horde;
    return 0;
}
