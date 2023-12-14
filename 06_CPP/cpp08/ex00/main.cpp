/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:54:09 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/14 10:24:08 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
int	easyfind(T& container, int target)
{
	typename T::iterator	data;
	data = find(container.begin(), container.end(), target);
	if (data != container.end())
	{
		std::cout << "[ " << *data << " ] : " << " Found in the container." << std::endl;
		return(1);
	}
	std::cout << "[ " << target << " ] : " <<" Not found in the container." << std::endl;
	return(0);
}

int		main(void)
{
	int					myint[]={299, 396, 298, 130, 3, 104, 442, 67, 89, 263};
	int					myint2[]={72, 49, 455, 165, 42, 8, 179, 77, 327, 172};
	std::list<int>		lst(myint, myint + sizeof(myint) / sizeof(int));
	std::list<int>		lst2(myint2, myint2 + sizeof(myint2) / sizeof(int));
	
	easyfind(lst, 104);
	easyfind(lst2, 104);
}
	
