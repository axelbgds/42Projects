/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:37:50 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 11:50:23 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime> 


int main(void) {

	std::cout << "[ Creating 10 Animal objects]" << std::endl;
	Animal *Animals[10];
	std::cout << std::endl;
    std::srand(std::time(0));
	
	std::cout << "[ Creating 5 Dog objects and 5 Cat objects]" << std::endl;
	for (int i = 0; i < 10; ++i) {
		if (not (i % 2)) {
			Animals[i] = new Dog();
			Animals[i]->makeSound();
			std::cout << std::endl;
		}
		else {
			Animals[i] = new Cat();
			Animals[i]->makeSound();
			std::cout << std::endl;
		}
	}

	std::cout << "[ Deleting ]" << std::endl;
	for (int i = 0; i < 10; ++i)
		delete Animals[i];

	return 0;
}