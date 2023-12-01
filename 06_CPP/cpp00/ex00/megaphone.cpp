/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:09:02 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/27 09:52:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
    if(ac == 1) {
        std::cout << "* LOUD AND UNBEATABLE FEEDBARCK NOISE *" <<std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        std::string str(av[i]);
        for(size_t j = 0; j < str.size(); j++) {
           str[j] = std::toupper(str[j]);
        }
        std::cout << str;
    }
    std::cout << std::endl;
    return 0;
}