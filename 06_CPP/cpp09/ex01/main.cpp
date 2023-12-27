/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 15:16:34 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <inverted Polish mathematical (RPN) expression>" << std::endl;
        return 1;
    }

    std::string expression = av[1];
    RPN rpn(expression);
    double result = rpn.processInput();

    std::cout << result << std::endl;

    return 0;
}