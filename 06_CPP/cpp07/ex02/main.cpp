/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:55:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/13 11:12:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// Test with a custom class
class YourType {
public:
    YourType() : data(0) {}  // Ajout du constructeur par défaut
    YourType(int value) : data(value) {}
    int getData() const { return data; }
private:
    int data;
};

int main() {
    // Test the Array class
    Array<int> intArray(5);

    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;
    }

    // Access elements using the subscript operator
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }

    std::cout << "\nArray size: " << intArray.size() << std::endl;

    // Create an Array of YourType
    Array<YourType> yourTypeArray(3);

    // Initialize elements with instances of YourType
    yourTypeArray[0] = YourType(10);
    yourTypeArray[1] = YourType(20);
    yourTypeArray[2] = YourType(30);

    // Access and print elements
    for (unsigned int i = 0; i < yourTypeArray.size(); ++i) {
        std::cout << yourTypeArray[i].getData() << " ";
    }

    std::cout << "\nArray size: " << yourTypeArray.size() << std::endl;

    return 0;
}

