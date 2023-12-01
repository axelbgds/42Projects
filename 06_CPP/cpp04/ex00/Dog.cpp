/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:51:16 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(): Animal() {
    std::cout << "Dog constructor" << std::endl;
    this->_type= "Dog";
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    std::cout << "Dog copy assignement operator" << std::endl;
    this->_type = rhs.getType();
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
