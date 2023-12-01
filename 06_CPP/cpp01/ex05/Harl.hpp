/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:58:46 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/02 16:03:13 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl {

    private :
        void debug();
        void info();
        void warning();
        void error();

    public :
        Harl();
        ~Harl();
        void    complain(std::string level);
};