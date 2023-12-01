/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:58:43 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/14 09:10:02 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

Harl::Harl (void) {
    return;
}

Harl::~Harl(void) {
    return;
}

void Harl::debug() {
    std::cout << "[Debug] : I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;
}

void Harl::info() {
    std::cout << "[Info] : I cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
              << std::endl;
}

void Harl::warning() {
    std::cout << "[Warning] : I think I deserve to have some extra bacon for free. I've been "
              << "coming for years whereas you started working here since last month."
              << std::endl;
}

void Harl::error() {
    std::cout << "[Error] : This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void    Harl::complain(std::string level) {
	std::string message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fonction[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i)
		if (not (message[i].compare(level)))
			(this->*fonction[i])();
}