
#include "easyfind.hpp"

template<typename T>
int	easyfind(T& container, int lycos)
{
	typename T::iterator	place;
	place = find(container.begin(), container.end(), lycos);
	if (place != container.end())
	{
		std::cout << "Found " << *place << " in list." << std::endl;
		return(1);
	}
	return(0);
}

int		main(void)
{
	int					myint[]{299, 396, 298, 130, 3, 104, 442, 67, 89, 263};
	int					myint2[]{72, 49, 455, 165, 42, 8, 179, 77, 327, 172};
	std::list<int>		lst(myint, myint + sizeof(myint) / sizeof(int));
	std::list<int>		lst2(myint2, myint2 + sizeof(myint2) / sizeof(int));
	
	easyfind(lst, 104);
	easyfind(lst2, 104);
}
	
