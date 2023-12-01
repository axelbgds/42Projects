/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:22:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/28 16:23:59 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    
}

Serializer::Serializer(Serializer const &other)
{
    *this = other;
}

Serializer::~Serializer()
{
    
}

Serializer  &Serializer::operator=(Serializer const &)
{
    return (*this);
}

uintptr_t  Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}