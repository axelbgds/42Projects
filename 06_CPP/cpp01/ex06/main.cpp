/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:46 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/13 11:54:28 by abeaugra         ###   ########.fr       */
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
		harl.complain(std::string(av[1]));
		return 0;
	}
	std::cerr << "Error: usage is " << av[0] << " \"DEBUG, INFO, WARNING, ERROR or something that you would like to say\" " << std::endl;
	exit(1);
}