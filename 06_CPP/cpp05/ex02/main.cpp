/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:19 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void) {

	srand(time(NULL));
	Bureaucrat bA("A", 146);
	ShrubberyCreationForm sf("Shrubbery Form");
	RobotomyRequestForm rf("Robotomy Form");
	RobotomyRequestForm rf2("Robotomy Form");
	PresidentialPardonForm pf("Presidential Form");
	std::cout << std::endl;

	std::cout << bA << std::endl;
	std::cout << sf << std::endl;
	bA.signForm(sf);
	bA.executeForm(sf);
	bA.upGrade();
	std::cout << bA << std::endl;
	bA.signForm(sf);
	std::cout << sf << std::endl;
	bA.executeForm(sf);
	bA.changeGrade(137);
	bA.executeForm(sf);
	std::cout << rf << std::endl;
	std::cout << bA << std::endl;
	bA.signForm(rf);
	std::cout << pf << std::endl;
	bA.signForm(pf);
	bA.changeGrade(1);
	bA.signForm(rf);
	std::cout << rf << std::endl;
	bA.executeForm(rf);
	bA.signForm(pf);
	std::cout << pf << std::endl;
	bA.executeForm(pf);
	
	std::cout << std::endl;
	bA.signForm(rf2);
	bA.executeForm(rf2);
	std::cout << std::endl;

	return 0;
}