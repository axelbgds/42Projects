/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:44:21 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:59:53 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->_type = rhs.getType();
    return *this;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::MakeSound() const
{
	std::cout << "WrongAnimal sound piouuuuuuu piouuuuuuu" << std::endl;
}