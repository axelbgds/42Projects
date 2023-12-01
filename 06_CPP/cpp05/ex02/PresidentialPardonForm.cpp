/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:47:36 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:21 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential Form", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm " << this->getName() << " constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()) {
	std::cout << "PresidentialPardonForm " << this->getName() << " copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() { 
	std::cout << "PresidentialPardonForm" << this->getName() << " destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {

	if (this != &rhs)
		AForm::operator=(rhs);

	std::cout << "PresidentialPardonForm " << this->getName() << " assignment operator called" << std::endl;

	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {

	if (this->getSigned() and executor.getGrade() <= this->getExecGrade())
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	else if (not this->getSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &presidentialpardonform) {
	o << "AForm " << presidentialpardonform.getName() << " | signGrade: " << presidentialpardonform.getSignGrade() << " | execGrade: " << presidentialpardonform.getExecGrade() << " | signStatus: " << presidentialpardonform.signStatus();

	return o;
}