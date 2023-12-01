/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:58:08 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/31 15:43:57 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include "Contact.class.hpp"

class Phonebook {
    private :
        Contact _contactsList[8];
        int     _contactCount;

    public :
        Phonebook();
        ~Phonebook();

        int         getContactCount() const;
        bool        addContact(const Contact& contact);
        std::string truncateString (const std::string& str, int width);
        void        list();
        void        displayContact(int index);
};