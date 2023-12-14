/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:24:17 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/14 12:57:57 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int i) : _size(i) {
}

Span::~Span() {}

Span::Span(const Span& src) {
    vect = src.vect;
    _size = src._size;
}

Span& Span::operator=(const Span& src) {
    if (this != &src) {
        vect = src.vect;
        _size = src._size;
    }
    return *this;
}

void Span::printNumbers() const {
    std::cout << "Container vector contains the following numbers: ";
    for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Span::addNumber(int number) {
    if (vect.size() < _size)
        vect.push_back(number);
    else
        throw std::runtime_error("Error: can't add number more elements to the array");
}

void Span::addMore(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (vect.size() + std::distance(begin, end) > _size)
        throw std::runtime_error("Error: can't add more elements to the array");
    else
        vect.insert(vect.end(), begin, end);
}

int Span::longestSpan() {
    if (vect.size() > 1) {
        std::sort(vect.begin(), vect.end());
        return *vect.rbegin() - *vect.begin();
    }
    throw std::runtime_error("Error: not enough elements to call the function");
}

int Span::shortestSpan() {
    if (vect.size() > 1) {
        std::sort(vect.begin(), vect.end());
        int minSpan = INT_MAX;  // Utilisez INT_MAX au lieu de std::numeric_limits<int>::max()
        for (std::vector<int>::iterator it = vect.begin(); it != vect.end() - 1; ++it) {
            minSpan = std::min(minSpan, *(it + 1) - *it);
        }
        return minSpan;
    }
    throw std::runtime_error("Error: not enough elements to call the function");
}

std::vector<int> Span::getVect() const {
    return vect;
}