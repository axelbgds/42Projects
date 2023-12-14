/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:24:10 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/14 12:58:24 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int randNumber(int max) {
    return rand() % max + 1; // Utilisez rand() pour obtenir un nombre aléatoire
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    try {
        // Test 1
        Span test(100);

        // Ajoutez les mêmes nombres que dans votre exemple
        int test1DataArray[] = {6, 3, 17, 9, 11};
        std::vector<int> test1Data(test1DataArray, test1DataArray + sizeof(test1DataArray) / sizeof(int));
        test.addMore(test1Data.begin(), test1Data.end());

        std::cout << "TEST 1: \n";
        test.printNumbers();  // Affichez les nombres pour vérification
        std::cout << "Shortest Span 1: " << test.shortestSpan() << std::endl;
        std::cout << "Longest Span 1: " << test.longestSpan() << std::endl;

        // Test 2
        std::vector<int> vecToAdd;
        vecToAdd.push_back(randNumber(5));
        vecToAdd.push_back(randNumber(5));

        Span test2(3);
        test2.addMore(vecToAdd.begin(), vecToAdd.end());
        std::cout << "TEST 2: \n";
        test2.printNumbers();
        std::cout << "Shortest Span 2: " << test2.shortestSpan() << std::endl;
        std::cout << "Longest Span 2: " << test2.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

