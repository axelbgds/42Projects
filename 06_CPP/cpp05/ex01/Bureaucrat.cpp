/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:58:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/24 13:29:16 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << this->_name << " destructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {
    std::cout << "Bureaucrat " << this->_name << "copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
        (std::string&)this->_name = rhs._name;
        this->_grade = rhs._grade;
    }
    std::cout << "Bureaucrat " << this->_name << " assignment operator" << std::endl;
    return *this;
}

std::string const Bureaucrat::getName(void) const {
    return this->_name;
}

int     Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void    Bureaucrat::upGrade(void) {
    std::cout<< "upGrade() " << this->_name << std::endl;
    if (this->_grade -1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::downGrade(void) {
    std::cout << "downGrade() " << this->_grade << std::endl;
    if(this->_grade +1 > 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::signForm(Form &form) const {
	std::cout << "signForm() " << this->_name << " called: " ;
	try {
		form.beSign(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << this->_name << " could not sign " << form.getName() << " because \"" << e.what() << "\""<< std::endl;
	}
}

const char  *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade to high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade to low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &Bureaucrat) {
    o << "Bureaucrat "<< Bureaucrat.getName() << " grade is " << Bureaucrat.getGrade();
    return o;
}
