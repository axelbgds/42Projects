/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 11:53:30 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <string>

Dog::Dog(): _Brain(new Brain) {
    this->_type = "Dog";
    std::cout << "Dog constructor" << std::endl;
    this->myIdeas = this->_Brain->getIdeas(0);
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
    if(this->_Brain)
        delete this->_Brain;
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
    if(this != &rhs) {
        if(this->_Brain)
            delete this->_Brain;
        this->_Brain = new Brain(*rhs._Brain);
        this->Animal::operator=(rhs);
    }
    std::cout << "Dog assignement operator" << std::endl;
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Dog makesound : Woof! Woof!" << std::endl;
    std::cout << "Look my idea[0] : " << myIdeas << std::endl;
}

Brain   *Dog::getBrain(void) const {
    return this->_Brain;
}
