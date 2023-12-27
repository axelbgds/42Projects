/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 10:42:55 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

/* Ouvre le fichier spécifié, remplit la base de données avec "data.csv",
et traite le fichier d'entrée. */
BitcoinExchange::BitcoinExchange(char *tab[]) {
    std::ifstream input(tab[1]);
    if (!input.is_open())
        throw NotOpen();
    input.close();
    fillBase();
    checkInput(tab[1]);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    this->_base = rhs.getBase();
    return (*this);
}

std::map<std::string, float> BitcoinExchange::getBase() const {
    return (this->_base);
}

// Classe d'exception pour signaler l'impossibilité d'ouvrir un fichier.
char const * BitcoinExchange::NotOpen::what() const throw() {
    return ("Error: could not open file.");
}

//Check data in fd
void BitcoinExchange::checkInput(const std::string& filename) {
    std::string date;
    std::string line;
    float value;
    int i = 0;

    std::ifstream ifs(filename.c_str());

    while (std::getline(ifs, line)) {
        if (line.find("|") == std::string::npos)
            std::cout << "Error: bad input => " << line << std::endl;
        else if (i != 0) {
            std::istringstream iss(line);
            if (std::getline(iss, date, '|') && iss >> value) {
                try {
                    validInput(date, value);
                    this->_base.insert(std::make_pair(date, value));
                    printRes(date, value);
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            }
        }
        i++;
    }
}

// put bdd with data.csv
void BitcoinExchange::fillBase() {
    std::ifstream ifsb("data.csv");
    std::string line;

    while (std::getline(ifsb, line)) {
        std::string date;
        float value;

        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            date = line.substr(0, pos);
            value = atof(line.substr(pos + 1).c_str());

            this->_base.insert(std::make_pair(date, value));
        } else {
            // Gestion d'une ligne sans délimiteur
            std::cerr << "Error: bad input in line => " << line << std::endl;
        }
    }

    ifsb.close();
}

void BitcoinExchange::validInput(const std::string& date, float value) {
    std::string ok = date;
    std::string yy, mm, dd, len;

    std::istringstream iss(ok);
    std::getline(iss, yy, '-');
    std::getline(iss, mm, '-');
    std::getline(iss, dd, '\0');

    len = yy + mm + dd;
    if (len.length() > 10 || len.length() < 9)
        throw std::logic_error("Error: invalid date format => " + date);
    if ((atoi(len.c_str()) > 20231109) || atoi(len.c_str()) < 20090102)
        throw std::logic_error("Error: date out of range => " + date);
    if (atoi(mm.c_str()) > 12 || atoi(dd.c_str()) > 31)
        throw std::logic_error("EError: invalid date components =>" + date);
    if (value > 1000)
        throw std::logic_error("Error: too large number.");
    if (value < 0)
        throw std::logic_error("Error: not positive number");

    std::map<std::string, float>::iterator it = _base.find(date);

    if (it != _base.end()) {
        std::stringstream ss;
        std::string test = "";

        ss << value * it->second;
        ss >> test;
        throw std::logic_error(it->first + " => " + test);
    }
}

// check if find with our bdd the data in extern fd
void BitcoinExchange::printRes(const std::string& date, float value) {
    std::map<std::string, float>::iterator it = _base.find(date);
    if (it != _base.end()) {
        std::cout << it->first;
        --it;
        std::cout << " => " << value << " = " << (value * it->second) << std::endl;

        this->_base.erase(date);
    }
}
