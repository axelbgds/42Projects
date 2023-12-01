/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:39:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 17:31:16 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &rhs);

        std::string getType() const;
        virtual void makeSound() const;

};