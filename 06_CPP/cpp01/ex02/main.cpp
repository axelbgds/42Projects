/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:13:49 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/01 15:29:53 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "adress from string : " << &str << std::endl;
    std::cout << "adress from stringPTR : " << stringPTR << std::endl;
    std::cout << "adress from stringREF : " << &stringREF << std::endl;
    
    std::cout << std::endl;

    std::cout << "value from string : " << str << std::endl;
    std::cout << "value from stringPTR : " << *stringPTR << std::endl;
    std::cout << "value from stringREF : " << stringREF << std::endl;

    return 0;
}