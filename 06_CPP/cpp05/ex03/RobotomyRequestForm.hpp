/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:47:34 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:33 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <sys/time.h>

class Bureaucrat;

class AForm;

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	void execute(Bureaucrat const &executor) const;

private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &robotomyrequestform);

#endif