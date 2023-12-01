/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:28:31 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 11:25:24 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain() {
    for (int i = 0; i < 100; ++i) {
        std::ostringstream oss;
        oss << rand() % 101;
        this->ideas[i] = oss.str(); //génère un index idée entre 0 et 100
    }
    std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(const Brain &src) {
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain copy constructor" << std::endl;
}

std::string const Brain::getIdeas(int i) const {
    return (this->ideas[i]);
}

Brain &Brain::operator=(Brain const &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = rhs.ideas[i];
    }
    std::cout << "Brain assignment operator" << std::endl;
    return *this;
}
