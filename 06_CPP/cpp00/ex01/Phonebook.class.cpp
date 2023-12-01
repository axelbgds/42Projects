/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:58:12 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/31 15:44:22 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Phonebook.class.hpp"

Phonebook::Phonebook():_contactCount(0) {
    // _contactCount = 0;
}

Phonebook::~Phonebook() {
    // std::cout << "Destructor Phonebook" << std::endl;
}

int     Phonebook::getContactCount() const {
    return this->_contactCount;
}

bool Phonebook::addContact(const Contact& contact) {
    if (_contactCount < 8) {
        _contactsList[_contactCount]= contact;
        _contactCount++;
        return true;
    }
    else {
        int nextIndex = (_contactCount % 8);
        _contactsList[nextIndex] = contact;
        return true;
    }
    return true;
}

// trunc std::string > length
std::string Phonebook::truncateString (const std::string& str, int width) {
    if (str.length() > static_cast<unsigned int>(width))
        return str.substr(0, width - 1) + ".";
    else
        return str;
}

// show list contact
void    Phonebook::list() {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

    for(int i = 0; i < _contactCount; i++) {
        const Contact& contact = _contactsList[i];

        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << this->truncateString(contact.getFirstName(),10) << "|";
        std::cout << std::setw(10) << this->truncateString(contact.getLastName(),10) << "|";
        std::cout << std::setw(10) << this->truncateString(contact.getNickName(),10) << "|" << std::endl;
    }
}

void Phonebook::displayContact(int index) {
    if (index >= 0 && index < _contactCount) {
        const Contact& contact = _contactsList[index];
        std::cout << std::setw(10) << "Index" << "|";
        std::cout << std::setw(10) << "First Name" << "|";
        std::cout << std::setw(10) << "Last Name" << "|";
        std::cout << std::setw(10) << "NickName" << "|" << std::endl;
        std::cout << std::setw(10) << index << "|";
        std::cout << std::setw(10) << this->truncateString(contact.getFirstName(),10) << "|";
        std::cout << std::setw(10) << this->truncateString(contact.getLastName(),10) << "|";
        std::cout << std::setw(10) << this->truncateString(contact.getNickName(),10) << "|" << std::endl;
    }
    else
        std::cout << "Invalid index. Please enter a valid index." << std::endl;

}