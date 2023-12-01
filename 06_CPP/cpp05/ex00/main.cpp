/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 15:59:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {

	try {
		Bureaucrat bureaucrat1("A", 151);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat bureaucrat2("B", 0);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat bureaucrat3("C", 5);

	for (int i = 0; i < 5; ++i) {
		std::cout << bureaucrat3 << std::endl;
		try {
			bureaucrat3.upGrade();
		}
		catch (Bureaucrat::GradeTooHighException const &e) {
			std::cerr << e.what() << std::endl;
			std::cout << bureaucrat3 << std::endl;
		}
	}
	std::cout << std::endl;

	Bureaucrat bureaucrat4("D", 146);

	for (int i = 0; i < 5; ++i) {
		std::cout << bureaucrat4 << std::endl;
		try {
			bureaucrat4.downGrade();
		}
		catch (Bureaucrat::GradeTooLowException const &e) {
			std::cerr << e.what() << std::endl;
			std::cout << bureaucrat4 << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}