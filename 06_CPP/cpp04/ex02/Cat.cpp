/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 11:53:37 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>

Cat::Cat(): _Brain(new Brain) {
    std::cout << "Cat constructor" << std::endl;
    this->_type = "Cat";
    this->myIdeas = this->_Brain->getIdeas(0);
}

Cat::~Cat() {
    std::cout << "Cat destructor" <<std::endl;
    if(this->_Brain)
        delete this->_Brain;
}

Cat::Cat(const Cat &rhs) : Animal(rhs) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    if(this != &rhs)
    {
        if(this->_Brain)
            delete this->_Brain;
        this->_Brain = new Brain(*rhs._Brain);
        this->Animal::operator=(rhs);
    }
    std::cout << "Cat assignement operator" << std::endl;
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Cat makesound : Miaouuuuuuuuuuuuuuuuuu" << std::endl;
    std::cout << "Look my idea[0] : " << myIdeas << std::endl;
}

Brain   *Cat::getBrain(void) const {
    return this->_Brain;
}
