/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:57 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/17 15:10:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:


	public:

	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap& operator=(ScavTrap const &rhs);
	ScavTrap(ScavTrap const &src);

	void	attack(const std::string& target);
	void	guardGate();
};