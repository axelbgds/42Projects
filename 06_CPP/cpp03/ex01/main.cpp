/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:30:36 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:24:43 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main(void) {

	std::cout << "[ Default constructor ]" << std::endl;
	ScavTrap Test;
	std::cout << std::endl;

	std::cout << "[ ScavTrap Constructor ]" << std::endl;
	ScavTrap Kevin("Kevin");
	std::cout << std::endl;

	std::cout << "[ Copy constructor ]" << std::endl;
	ScavTrap copyKevin(Kevin);
	std::cout << std::endl;

	std::cout << "[ Assignment operator ]" << std::endl;
	ScavTrap copyOperator("copyOperator");
	copyOperator = Kevin;
	std::cout << std::endl;

	std::cout << "[ attack() ]" << std::endl;
	Kevin.attack("Roco");
	Kevin.attack("Clara");
	Kevin.attack("Roco");
	Kevin.attack("Clara");
	std::cout << std::endl;

	std::cout << "[ takeDamage() ]" << std::endl;
	Kevin.takeDamage(2);
	Kevin.takeDamage(2);
	std::cout << std::endl;

	std::cout << "[ beRepaired() ]" << std::endl;
	Kevin.beRepaired(1);
	Kevin.beRepaired(1);
	std::cout << std::endl;

	std::cout << "[ guardGate() ]" << std::endl;
	Kevin.guardGate();
	std::cout << std::endl;

	std::cout << "[ Destructor ]" << std::endl;

	return 0;
}