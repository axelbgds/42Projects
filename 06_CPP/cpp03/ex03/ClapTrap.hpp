/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 15:10:03 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class ClapTrap
{
        protected:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _nrgpoints;
        unsigned int _atkdmg;


	public:
	ClapTrap();
	ClapTrap(std::string const name);
	~ClapTrap();
	ClapTrap(ClapTrap const &src);
	ClapTrap& operator=(ClapTrap const &rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};