/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:44:27 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:59:54 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
			WrongCat();
			virtual ~WrongCat();
			WrongCat(WrongCat const &src);
			WrongCat& operator=(WrongCat const &rhs);
			void makeSound() const;
};