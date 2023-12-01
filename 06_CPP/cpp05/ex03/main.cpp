/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:38:31 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main(void) {
	
	Intern someRandomIntern;
	AForm *rsf = someRandomIntern.makeForm("shrubbery creation", "Shrubbery Target");
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Robotomy Target");
	AForm *rpf = someRandomIntern.makeForm("presidential pardon", "Presidential Target");
	std::cout << std::endl;

	Bureaucrat bA("A", 146);
	std::cout << bA << std::endl;
	std::cout << *rsf << std::endl;
	bA.signForm(*rsf);
	bA.executeForm(*rsf);
	bA.upGrade();
	std::cout << bA << std::endl;
	bA.signForm(*rsf);
	std::cout << *rsf << std::endl;
	bA.executeForm(*rsf);
	bA.changeGrade(137);
	bA.executeForm(*rsf);
	bA.changeGrade(1);
	std::cout << *rrf << std::endl;
	bA.signForm(*rrf);
	std::cout << *rrf << std::endl;
	bA.executeForm(*rrf);
	std::cout << *rpf << std::endl;
	bA.signForm(*rpf);
	std::cout << *rpf << std::endl;
	bA.executeForm(*rpf);
	std::cout << std::endl;

	someRandomIntern.makeForm("42 form", "");
	std::cout << std::endl;

	delete rsf;
	delete rrf;
	delete rpf;

	return 0;
}