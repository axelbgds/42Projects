/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:24:52 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/28 15:33:28 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <sstream>

class ScalarConverter {

    public:
        static void     convert(std::string const &str);

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ~ScalarConverter();
        ScalarConverter &operator=(ScalarConverter const &rhs);

        static void     convertChar(std::string const &str);
        static void     convertInt(std::string const &str);
        static void     convertFloat(std::string const &str);

        static void     convertDouble(std::string const &str);
        static int      checkDigit(std::string const &str);

};