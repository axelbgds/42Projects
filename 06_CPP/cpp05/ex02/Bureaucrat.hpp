/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:00 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>
# include <exception>
# include <cstdlib>

class AForm;

class Bureaucrat {

public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string const   getName(void) const;
	int                 getGrade(void) const;

	void                changeGrade(unsigned int const grade);
	void                upGrade(void);
	void                downGrade(void);
	void                signForm(AForm &form) const;
	void                executeForm(AForm const &form);

	class GradeTooHighException: public std::exception {
		public: const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public: const char *what() const throw();
	};

private:
	std::string const   _name;
	int                 _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif