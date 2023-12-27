/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 10:25:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(char *tab[]);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);

    std::map<std::string, float> getBase() const;

    class NotOpen : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    void checkInput(const std::string& filename);
    void fillBase();
    void validInput(const std::string& date, float value);
    void printRes(const std::string& date, float value);

private:
    std::map<std::string, float> _base;

};