/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:23:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:33:35 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <memory>

class Intern {

public:
	Intern(void);
	Intern(Intern const &src);
	~Intern(void);

	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string const &form, std::string const &target);

private:
	typedef AForm* (*FuncPtr)(std::string const &target);
};

std::ostream &operator<<(std::ostream &o, Intern const &intern);

#endif