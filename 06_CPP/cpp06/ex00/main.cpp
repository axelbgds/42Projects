/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:19:06 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/28 14:36:49 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* av[]) 
{
    if (argc != 2) 
	{
        std::cerr << "Please write the correct number of arguments" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);

    return (0);
}