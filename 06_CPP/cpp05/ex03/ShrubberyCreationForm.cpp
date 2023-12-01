/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:28:30 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:22:11 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Form", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm " << this->getName() << " constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()) {
	std::cout << "ShrubberyCreationForm " << this->getName() << " copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { 
	std::cout << "ShrubberyCreationForm" << this->getName() << " destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {

	if (this != &rhs)
		AForm::operator=(rhs);

	std::cout << "ShrubberyCreationForm " << this->getName() << " assignment operator called" << std::endl;

	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	if (this->getSigned() and executor.getGrade() <= this->getExecGrade()) {
		std::ofstream outfile(std::string(this->_target+"_shrubbery").c_str());
		outfile << "   .----." << std::endl;
        outfile << "  /      \\" << std::endl;
        outfile << " |  o  o |" << std::endl;
        outfile << " |  \\__/ |" << std::endl;
        outfile << "  \\_____/" << std::endl;
		outfile.close();
	} 
	else if (not this->getSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &shrubberycreationform) {
	o << "AForm " << shrubberycreationform.getName() << " | signGrade: " << shrubberycreationform.getSignGrade() << " | execGrade: " << shrubberycreationform.getExecGrade() << " | signStatus: " << shrubberycreationform.signStatus();

	return o;
}