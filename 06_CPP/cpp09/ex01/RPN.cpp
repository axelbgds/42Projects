/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 15:16:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &expression) : _expression(expression) {
}

RPN::~RPN() {
}

/* Process the input expression and perform calculations using Reverse Polish Notation (RPN) */
double RPN::processInput() {
    for (std::string::const_iterator it = _expression.begin(); it != _expression.end(); ++it) {
        if (std::isdigit(*it)) {
            _calculation.push(static_cast<double>(*it - '0'));
        } else if (isValidOperator(*it)) {
            if (_calculation.size() < 2) {
                std::cerr << "Error: Not enough operands for operator " << *it << std::endl;
                exit(EXIT_FAILURE);
            }
            double n2 = _calculation.top();
            _calculation.pop();
            double n1 = _calculation.top();
            _calculation.pop();
            double result = doCalculation(*it, n1, n2);
            _calculation.push(result);
        } else if (std::isspace(*it)) {
            continue;
        } else {
            std::cerr << "Error: Invalid input character: " << *it << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (_calculation.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        exit(EXIT_FAILURE);
    }

    double result = _calculation.top();
    _calculation.pop();

    return result;
}

/* Check if the given character is a valid operator (+, -, *, /) */
bool RPN::isValidOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/* Perform the specified calculation (addition, subtraction, multiplication, or division) */
double RPN::doCalculation(char op, double n1, double n2) {
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            if (n2 != 0) {
                return n1 / n2;
            } else {
                std::cerr << "Error: Division by zero" << std::endl;
                exit(EXIT_FAILURE);
            }
        default:
            std::cerr << "Error: Invalid operator: " << op << std::endl;
            exit(EXIT_FAILURE);
    }
}