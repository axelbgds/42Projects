/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 11:18:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>


class Cat : public Animal {
    public :
        Cat();
        ~Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &rhs);

        void makeSound() const;

        Brain *getBrain(void) const;

    private:
        std::string myIdeas;
        Brain   *_Brain;
};

