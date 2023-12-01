/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:51:14 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>


class Cat : public Animal {
    public :
        Cat();
        ~Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &rhs);
        void makeSound() const;
};

