/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:05:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 12:24:42 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
	unsigned int getHitpoints() const;
	unsigned int getEnergy() const;
	unsigned int getDamage() const;

protected:
	std::string _name;
	unsigned int _hitpoints;
	unsigned int _energy;
	unsigned int _damage;
};
