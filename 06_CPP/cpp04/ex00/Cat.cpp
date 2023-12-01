/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 09:41:14 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {
    std::cout << "Cat constructor" << std::endl;
    this->_type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat destructor" <<std::endl;
}

Cat::Cat(const Cat &rhs) : Animal(rhs) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    std::cout << "Cat copy assignement operator" << std::endl;
    this->_type = rhs.getType();
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Miaouuuuuuuuuuuuuuuuuu" << std::endl;
}
