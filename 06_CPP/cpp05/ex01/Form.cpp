/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:54:36 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/28 11:19:21 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int gradeSign, int gradeExec) : _name(name), _signGrade(gradeSign), _execGrade(gradeExec) {
    std::cout << "Form " << this->_name << " constructor" << std::endl;
    if(this->_signGrade < 1 or this->_execGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(this->_signGrade > 150 or this->_execGrade >150)
        throw Bureaucrat::GradeTooLowException();
    _signB = false;
}

Form::Form(Form const &src) :_name(src._name), _signB(src._signB),_signGrade(src._signGrade), _execGrade(src._execGrade) {
    std::cout << "Form " << this->_name << "copy constructor" << std::endl;
}

Form::~Form(void) {
    std::cout << "Form " << this->_name << " destructor" << std::endl;
}

Form &Form::operator=(Form const &rhs) {
    if(this != &rhs) {
        (std::string&)this->_name = rhs._name;
        this->_signB = rhs._signB;
        (int &)this->_signGrade = rhs._signGrade;
        (int &)this->_execGrade = rhs._execGrade;
    }
    std::cout << "Form " << this->_name << " assignement operator" << std::endl;
    return *this;
}

std::string const Form::getName(void) const {
    return this->_name;
}

int Form::getSignGrade(void) const {
    return this->_signGrade;
}

int Form::getExecGrade(void) const {
    return this->_execGrade;
}

std::string Form::signStatus(void) const {
    if(this->_signB)
        return ("signed");
    else
        return ("not signe");
}

void Form::beSign(Bureaucrat const &bureaucrat) {
    if(bureaucrat.getGrade() <= this->_signGrade)
        this->_signB = 1;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade to high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade to low";
}

std::ostream &operator<<(std::ostream &a, Form const &form) {
    a << "Form " << form.getName() << " | signGrade: " << form.getSignGrade() << " | execGrade: " << form.getExecGrade() << " | signStatus: " << form.signStatus();
    return a;
}