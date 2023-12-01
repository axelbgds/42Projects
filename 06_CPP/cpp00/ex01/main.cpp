/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:27:16 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/29 14:38:16 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "Phonebook.class.hpp"

int main(void) {
    Phonebook Phonebook;

    while(true) {
        std::string cmd;
        std::cout << "Enter a command (ADD, LIST, SEARCH, EXIT): ";
        std::cin >> cmd;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        
        if (cmd == "ADD") {
            std::string firstName;
            std::string lastName;
            std::string nickName;
            std::string phoneNumber;
            std::string darkestSecret;

            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickName: ";
            std::getline(std::cin, nickName);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);

            if(!firstName.empty() && !lastName.empty() && !nickName.empty() && !phoneNumber.empty()
            && !darkestSecret.empty()) {  
                
                Contact *newContact =  new Contact(firstName, lastName, nickName, phoneNumber,  darkestSecret);
                
                if (Phonebook.addContact(*newContact))
                    std::cout << "Contact added succesfully." << std::endl;
            }
            else {
                 std::cout << "Empty informations." << std::endl;
            }
        }
        else if (cmd == "SEARCH") {
            int index;
            std::cout << "Enter the index of the contact that you want to display: ";
            std::cin >> index;

            if (index >= 0 && index < Phonebook.getContactCount()){
                std::cout << std::endl;
                Phonebook.displayContact(index);
                std::cout << std::endl;
            }
            else
                std::cout << "Invalid index. Please enter a valid index." << std::endl;
        }
        else if (cmd == "LIST") {
            std::cout << std::endl;
            Phonebook.list();
            std::cout << std::endl;
        }
        else if (cmd == "EXIT") {
            break;
        }
        else {
            std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." <<std::endl;
        }
    }
    return 0;
}