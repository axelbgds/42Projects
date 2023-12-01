/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:47:27 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:23 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	void execute(Bureaucrat const &executor) const;

private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &presidentialpardonform);

#endif