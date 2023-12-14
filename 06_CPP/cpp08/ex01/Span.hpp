/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:24:02 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/14 12:38:32 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

class Span {
public:
    Span(unsigned int i);
    ~Span();
    Span(const Span& src);
	Span& operator=(const Span& src);

    void printNumbers() const;
    void addNumber(int i);
    void addMore(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();
	
    std::vector<int> getVect() const;

private:
    std::vector<int> vect;
    unsigned int _size;
};


