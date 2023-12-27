/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 15:16:37 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cstdlib>
#include <cctype> // Utilisé pour isspace

class RPN {
public:
    RPN(std::string const &expression);
    ~RPN();

    double processInput();

private:
    RPN();
	RPN(RPN const &src);
    RPN &operator=(RPN const &rhs);

    std::string _expression;
    std::stack<double> _calculation;

    bool isValidOperator(char c) const;
    double doCalculation(char op, double n1, double n2);
};

#endif
