/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:54:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/27 13:54:21 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form {
    
    public:
        Form(std::string const &name, int gradeSign, int gradeExec);
        Form(Form const &src);
        ~Form();

        Form& operator=(Form const &rhs);
        
        std::string const   getName(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        std::string         signStatus(void) const;

        void                beSign(Bureaucrat const &bureaucrat);

        class   GradeTooHighException: public std::exception {
            public: const char *what() const throw();
        };

        class   GradeTooLowException: public std::exception {
            public: const char *what() const throw();
        };

    private :
        std::string const   _name;
        bool                _signB;
        const int           _signGrade;
        const int           _execGrade;


};

std::ostream &operator<<(std::ostream &a, Form const &form);