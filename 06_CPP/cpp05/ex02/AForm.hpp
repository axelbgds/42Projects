/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:54:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:09 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <fstream>

class Bureaucrat;

class AForm {

public:
	AForm(std::string const &name, int gradeSign, int gradeExec);
	AForm(AForm const & src);
	~AForm(void);

	AForm &operator=(AForm const &rhs);

	std::string const getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	std::string signStatus(void) const;
	bool getSigned(void) const;

	void beSigned(Bureaucrat const &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException: public std::exception {
		public: const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public: const char *what() const throw();
	};
	class FormNotSignedException: public std::exception {
		public: const char *what() const throw();
	};

private:
	std::string const _name;
	bool _isSigned;
	int const _signGrade;
	int const _execGrade;
};

std::ostream &operator<<(std::ostream &o, AForm const &form);

#endif