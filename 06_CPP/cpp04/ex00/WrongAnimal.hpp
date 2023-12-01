/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:44:41 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/20 16:51:26 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	public:
			WrongAnimal();
			virtual ~WrongAnimal();
			WrongAnimal(WrongAnimal const &src);
			WrongAnimal& operator=(WrongAnimal const &rhs);
			std::string getType() const;
			void MakeSound() const;

	protected:
			std::string _type;
};