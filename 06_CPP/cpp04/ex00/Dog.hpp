/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:51:18 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal {
    
    public :
        Dog();
        ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &rhs);
        void makeSound() const;
};