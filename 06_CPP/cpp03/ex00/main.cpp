/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:28:35 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:24:30 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::cout << "[ Default constructor ]" << std::endl;
    ClapTrap Test;
    std::cout << std::endl;

    std::cout << "[ ClapTrap Constructor]" << std::endl;
    ClapTrap Jean("Jean");
    std::cout << std::endl;

    std::cout << "[ Copy Constructor]" << std::endl;
    ClapTrap copyJean("Jean");
    std::cout << std::endl;

    std::cout << "[ Assignment operator ]" << std::endl;
	ClapTrap copyOperator("copyOperator");
	copyOperator = Jean;
	std::cout << std::endl;

	std::cout << "[ attack() }" << std::endl;
	Jean.attack("Paul");
	Jean.attack("Charles");
	Jean.attack("Paul");
	Jean.attack("Charles");
	std::cout << std::endl;

	std::cout << "[ takeDamage() ]" << std::endl;
	Jean.takeDamage(2);
	Jean.takeDamage(2);
	std::cout << std::endl;

	std::cout << "[ beRepaired() ]" << std::endl;
	Jean.beRepaired(1);
	Jean.beRepaired(1);
	std::cout << std::endl;

	std::cout << "[ Destructor ]" << std::endl;
    return 0;

}