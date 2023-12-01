/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:51:12 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Generic Animal") {
    std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type) {
    std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
    if (this != &rhs) {
        _type = rhs._type;
    }
    std::cout << "Animal copy assignment operator" << std::endl;
    return *this;
}

std::string Animal::getType() const {
    return _type;
}

void    Animal::makeSound() const {
    std::cout << "Grrrr je suis un animal" << std::endl;
}