/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:47:32 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:32 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Form", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm " << this->getName() << " constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()) {
	std::cout << "RobotomyRequestForm " << this->getName() << " copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() { 
	std::cout << "RobotomyRequestForm" << this->getName() << " destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {

	if (this != &rhs)
		AForm::operator=(rhs);

	std::cout << "RobotomyRequestForm " << this->getName() << " assignment operator called" << std::endl;

	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	if (this->getSigned() and executor.getGrade() <= this->getExecGrade()) {
		std::cout << "Drilling noises... " << this->getName() << " trying to robotomized " << this->_target << std::endl;
		if (rand() % 2)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
	else if (not this->getSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &robotomyrequestform) {
	o << "AForm " << robotomyrequestform.getName() << " | signGrade: " << robotomyrequestform.getSignGrade() << " | execGrade: " << robotomyrequestform.getExecGrade() << " | signStatus: " << robotomyrequestform.signStatus();

	return o;
}