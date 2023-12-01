/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:00 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 13:58:18 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Form.hpp"
# include <iostream>
# include <exception>
# include <cstdlib>

class Form;

class Bureaucrat {

    public:
        Bureaucrat(std::string const &name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &src);

        Bureaucrat &operator=(Bureaucrat const &rhs);

        std::string const   getName(void) const;
        int                 getGrade(void) const;

        void    upGrade(void);
        void    downGrade(void);
        void    signForm(Form &form) const;
        
        class   GradeTooHighException: public std::exception {
            public: const char *what() const throw();
        };

        class   GradeTooLowException: public std::exception {
            public: const char *what() const throw();
        };

    private:
        std::string const   _name;
        int                 _grade;
};

    std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);
