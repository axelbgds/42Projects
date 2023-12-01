/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:39 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/13 14:23:59 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {

	int i;
	std::string message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; ++i)
		if (not(message[i].compare(level)))
			break ;

	switch (i) {
		case 0:
			debug();
			/* FALLTHRU */
		case 1:
			info();
			/* FALLTHRU */
		case 2:
			warning();
			/* FALLTHRU */
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}