/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:58:25 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/14 09:12:25 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {

	Harl harl;
	std::string message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac == 2) {
		for (int i = 0; i < 4; ++i) {
			if (not message[i].compare(av[1])) {
				harl.complain(std::string(av[1]));
				return 0;
			}
		}
	}
	std::cerr << "Error: usage is " << av[0] << " \"DEBUG, INFO, WARNING or ERROR\" " << std::endl;
	return 1;
}
