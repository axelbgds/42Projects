/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:24:49 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/28 15:39:06 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    *this = src;
}

ScalarConverter::~ScalarConverter() {   
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
    return *this;
}

void ScalarConverter::convertChar(std::string const &str) {
    int intValue = std::atoi(str.c_str());
    if (intValue >= 32 && intValue <= 126) {
        char c = static_cast<char>(intValue);
        std::cout << "char: " << c << "'" << std::endl;
    } else if (str.length() == 1 && str[0] >= 32 && str[0] <= 126) {
        std::cout << "char: " << str[0] << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void     ScalarConverter::convertInt(std::string const &str) {
    if (str[0]=='-' || str[0]=='+') {
        if (str[0] == '-' && isdigit(str[1])){
            int i = std::atoi(str.c_str());
            std::cout << "int: " << i << std::endl;
        }
    }
    else if (isdigit(str[0])) {
        int i = std::atoi(str.c_str());
        std::cout << "int: " << i << std::endl;
    } else {
        int j = static_cast<int>(str[0]);
        std::cout << "int: " << j << std::endl;
    }
}

void     ScalarConverter::convertFloat(std::string const &str) {
    if(str[0] == '-' || str[0] =='+') {
        if (str[0] == '-' && isdigit(str[1])) {
            float f = std::atoi(str.c_str());
            std::cout << "float: " << f << "0.f" << std::endl;
        }
        else {
            float f = std::atoi(str.c_str());
            std::cout << "float: " << f << ".0f" << std::endl;
        }
    }
    else if (isdigit(str[0])) { 
        if (str.find('.') != std::string::npos && (str.length() > 0 && str[str.length()-1]!= 'f'))
            std::cout << "float: " << str << std::endl;
        else if (str.length() > 0 && str[str.length()-1] == 'f')
            std::cout << "float: " << str << std::endl;
        else
            std::cout << "float: " << str << ".0f" << std::endl;
    }
    else {
        float f = static_cast<float>(str[0]);
        std::cout << "float: " << f << ".0f" << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string& str) 
{
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-' && isdigit(str[1]))
		{
			double	d = std::atoi(str.c_str());
			std::cout << "double : " << d << ".0" << std::endl;
		}
		else
		{
			double	d = std::atoi(str.c_str());
			std::cout << "double : " << d << ".0" << std::endl;
		}
	}
	else if (isdigit(str[0]))
	{
		if (str.find('.') != std::string::npos && (str.length() > 0 && str[str.length() - 1] != 'f'))
			std::cout << "double : " << str << std::endl;
		else if (str.find('.') != std::string::npos && (str.length() > 0 && str[str.length() - 1] == 'f'))
		{
			std::string str2 = str.substr(0, str.length() - 1);
			std::cout << "double : " << str2 << std::endl;
		}
		else
		{	
			double	d = std::atoi(str.c_str());
			std::cout << "double : " << d << ".0" << std::endl;
		}
	}
	else
	{
		double	d = static_cast<double>(str[0]);
		std::cout << "double : " << d << ".0" << std::endl;
	}
}

int	ScalarConverter::checkDigit(std::string const &str)
{
	if (str == "-inff" || str == "-inf") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
    	std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
		return 1;
    } 
	else if (str == "+inff" || str == "+inf") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
        std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
		return 1;
    } 
	else if (str == "nanf" || str == "nan") {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
		return 1;
    }
	return 0;
}


void	ScalarConverter::convert(std::string const &str)
{
	if (checkDigit(str) == 1)
		return ;
	else
	{
		convertChar(str);
		convertInt(str);
		convertFloat(str);
		convertDouble(str);
	}
}