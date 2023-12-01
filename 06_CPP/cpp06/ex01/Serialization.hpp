/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:22:00 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/28 16:23:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct  Data
{
    int value;
    Data(int val) : value(val) {}
};

class Serializer
{
    public:

        Serializer();
        Serializer(Serializer const &other);
        ~Serializer();
        Serializer  &operator=(Serializer const  &);
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);

};

#endif