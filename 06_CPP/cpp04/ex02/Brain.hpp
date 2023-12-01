/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:28:33 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/22 10:47:09 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
# include <string>
# include <cstdlib>

class Brain {
    
    public:
        Brain();
        ~Brain();
        Brain(const Brain &src);
        Brain &operator=(Brain const &rhs);
        std::string const getIdeas(int i) const;

        std::string ideas[100];
};