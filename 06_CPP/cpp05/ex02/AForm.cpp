/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:54:36 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/28 11:20:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(std::string const &name, int gradeSign, int gradeExec) : _name(name), _isSigned(0), _signGrade(gradeSign), _execGrade(gradeExec) {
	std::cout << "AForm " << this->_name << " constructor called" << std::endl;
	if (this->_signGrade < 1 or this->_execGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_signGrade > 150 or this->_execGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	_signB = false;
}

AForm::AForm(AForm const &src) : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade) {
	std::cout << "AForm " << this->_name << " copy constructor called" << std::endl;
}

AForm::~AForm(void) {
	std::cout << "AForm " << this->_name << " destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs) {

	if (this != &rhs) {
		(std::string&)this->_name = rhs._name;
		this->_isSigned = rhs._isSigned;
		(int &)this->_signGrade = rhs._signGrade;
		(int &)this->_execGrade = rhs._execGrade;
	}

	std::cout << "AForm " << this->_name << " assignment operator called" << std::endl;
	
	return *this;
}

std::string const AForm::getName(void) const {

	return this->_name;
}

int AForm::getSignGrade(void) const {

	return this->_signGrade;
}

int AForm::getExecGrade(void) const {

	return this->_execGrade;
}

std::string AForm::signStatus(void) const {

	if (this->_isSigned)
		return ("signed");
	else
		return ("not signed");
}

bool AForm::getSigned(void) const {

	return (this->_isSigned);
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {

	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = 1;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {

	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {

	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {

	return "Form not signed";
}

std::ostream &operator<<(std::ostream &o, AForm const &form) {
	o << "AForm " << form.getName() << " | signGrade: " << form.getSignGrade() << " | execGrade: " << form.getExecGrade() << " | signStatus: " << form.signStatus();

	return o;
}