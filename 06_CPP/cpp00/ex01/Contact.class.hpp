/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:02:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/28 13:31:21 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Contact {
    private :
        // mes var
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _secret;

    public :
        Contact(void);
        ~Contact(void);

        // Const for create contact
        Contact(const std::string& firstName, const std::string& lastName, 
                const std::string& nickName, const std::string& phoneNumber, 
                const std::string& darkestSecret);
        
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getSecret() const;

        // void setFirstName(std::string cmd);
        // void setLastName(std::string cmd);
        // void setNickName(std::string cmd);
        // void setPhoneNumber(std::string cmd);
        // void setSecret(std::string cmd);
};