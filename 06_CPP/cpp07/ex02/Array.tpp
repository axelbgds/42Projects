/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:01:30 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/13 11:14:08 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Array.tpp

// Constructor: Creates an empty array
template <typename T>
Array<T>::Array() : elements(0), arraySize(0) {}

// Constructor: Creates an array of n elements initialized by default
template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n) {
    elements = new T[n];  // Allocate memory for the array
}

// Copy Constructor: Creates a copy of the array
template <typename T>
Array<T>::Array(const Array<T>& other) : arraySize(other.arraySize) {
    elements = new T[arraySize];  // Allocate memory for the new array
    for (unsigned int i = 0; i < arraySize; ++i) {
        elements[i] = other.elements[i];  // Copy elements from the original array
    }
}

// Destructor: Frees the allocated memory
template <typename T>
Array<T>::~Array() {
    delete[] elements;  // Deallocate the memory used by the array
}

// Assignment Operator: Assigns the content of another array to this array
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {  // Check for self-assignment
        delete[] elements;  // Deallocate the current memory
        arraySize = other.arraySize;
        elements = new T[arraySize];  // Allocate new memory
        for (unsigned int i = 0; i < arraySize; ++i) {
            elements[i] = other.elements[i];  // Copy elements from the other array
        }
    }
    return *this;  // Return a reference to the modified array
}

// Subscript Operator: Accesses elements using the subscript operator []
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= arraySize) {
        throw std::exception();  // Throw std::exception for out-of-bounds access
    }
    return elements[index];  // Return a reference to the requested element
}

// Member Function size(): Returns the number of elements in the array
template <typename T>
unsigned int Array<T>::size() const {
    return arraySize;  // Return the size of the array
}

