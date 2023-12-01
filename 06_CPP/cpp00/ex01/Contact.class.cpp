/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:02:43 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/28 10:48:33 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(){
    // std::cout << "Constructeur Contact" << std::endl;
}

Contact::~Contact(){
    // std::cout << "Destructeur Contact" << std::endl;
}
Contact::Contact(const std::string& firstName, const std::string& lastName, 
    const std::string& nickName, const std::string& phoneNumber, 
    const std::string& darkestSecret):_firstName(firstName),_lastName(lastName), 
    _nickName(nickName), _phoneNumber(phoneNumber),_secret(darkestSecret) { // vérifier prk &
        
    }

// Déf get
std::string Contact::getFirstName() const {
    return this->_firstName;
}

std::string Contact::getLastName() const {
    return this->_lastName;
}

std::string Contact::getNickName() const {
    return this->_nickName;
}

std::string Contact::getPhoneNumber() const {
    return this->_phoneNumber;
}

std::string Contact::getSecret() const {
    return this->_secret;
}

// Def set modif possible pas en const sur class
// void Contact::setFirstName(std::string cmd) {
//     _firstName = cmd;
// }

// void Contact::setLastName(std::string cmd) {
//     _lastName = cmd;
// }

// void Contact::setNickName(std::string cmd) {
//     _nickName = cmd;
// }

// void Contact::setPhoneNumber(std::string cmd) {
//     _phoneNumber = cmd;
// }

// void Contact::setSecret(std::string cmd) {
//     _secret = cmd;
// }

