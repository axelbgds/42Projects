/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:23:34 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:33:58 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
	*this = src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void) { 
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs) {

	(void)rhs;

	std::cout << "Intern assignment operator called" << std::endl;

	return *this;
}

static std::string const names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

static AForm *createShrubberyCreationForm(std::string const &target) {

	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequestForm(std::string const &target) {

	return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardonForm(std::string const &target) {

	return new PresidentialPardonForm(target); 
}

AForm *Intern::makeForm(std::string const &form, std::string const &target) {
	// Array of pointers to member functions to handle the creation of Forms
	FuncPtr value[] = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};
	for (int i = 0; i < 3; ++i) {
		if (not names[i].compare(form)) {
			std::cout << "Intern creates " << form << std::endl;
			AForm* form = value[i](target);
			return form;
		}
	}
	std::cout << "Error: " << form << " does not exist" << std::endl;

	return NULL;
}