/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:55:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/13 11:13:10 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
    public:
        Array();
        explicit Array(unsigned int n);
        Array(const Array<T>& other);
        ~Array();

        // Assignment operator
        Array<T>& operator=(const Array<T>& other);

        // Subscript operator
        T& operator[](unsigned int index);

        // Member function size()
        unsigned int size() const;

    private:
        T* elements;
        unsigned int arraySize;
};

// Include the template implementation (optional)
#include "Array.tpp"

#endif // ARRAY_HPP

