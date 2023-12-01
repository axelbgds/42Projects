/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/24 13:25:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void) {

	Bureaucrat bureaucrat1("1", 7);
	Form formA("A", 4, 4);
	std::cout << std::endl;

	std::cout << bureaucrat1 << std::endl;
	bureaucrat1.signForm(formA);
	std::cout << formA << std::endl;
	std::cout << std::endl;

	bureaucrat1.upGrade();
	std::cout << bureaucrat1 << std::endl;
	bureaucrat1.signForm(formA);
	std::cout << formA << std::endl;
	std::cout << std::endl;

	bureaucrat1.upGrade();
	std::cout << bureaucrat1 << std::endl;
	bureaucrat1.signForm(formA);
	std::cout << formA << std::endl;
	std::cout << std::endl;

	bureaucrat1.upGrade();
	std::cout << bureaucrat1 << std::endl;
	bureaucrat1.signForm(formA);
	std::cout << formA << std::endl;

	std::cout << std::endl;
}