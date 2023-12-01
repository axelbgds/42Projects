/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 11:18:21 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal {
    
    public :
        Dog();
        ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &rhs);
        
        void makeSound() const;

        Brain   *getBrain(void) const;


    private:
        Brain   *_Brain;
        std::string myIdeas;
};