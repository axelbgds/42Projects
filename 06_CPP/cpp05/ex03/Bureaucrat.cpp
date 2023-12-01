/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:58:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:13 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade){
	std::cout << "Bureaucrat " << this->_name << " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {

	if (this != &rhs) {
		(std::string&)this->_name = rhs._name;
		this->_grade = rhs._grade;
	}

	std::cout << "Bureaucrat " << this->_name << " assignment operator called" << std::endl;
	
	return *this;
}

std::string const Bureaucrat::getName(void) const {

	return this->_name;
}

int Bureaucrat::getGrade(void) const {

	return this->_grade;
}

void Bureaucrat::changeGrade(unsigned int const grade) {
	this->_grade = grade;
	std::cout << "Grade of Bureaucrat " << this->_name << " is now changed to " << this->_grade << std::endl;
}

void Bureaucrat::upGrade(void) {
	std::cout << "upGrade() " << this->_name << " called" << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::downGrade(void) {
	std::cout << "downGrade() " << this->_name << " called" << std::endl;
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(AForm& form) const {
	std::cout << "signForm() " << this->_name << " called: " ;
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << this->_name << " could not sign " << form.getName() << " because \"" << e.what() << "\""<< std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {

	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} 
	catch (std::exception const &e) {
		std::cerr << this->_name << " could not execute " << form.getName() << " because \"" << e.what() << "\""<< std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat) {
	o << "Bureaucrat "<< bureaucrat.getName() << " grade is " << bureaucrat.getGrade();

	return o;
}