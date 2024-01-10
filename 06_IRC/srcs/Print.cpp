#include "../includes/ft_irc.hpp"

void printVectorUsers(std::vector<User *> &users)
{
	std::vector<User *>::iterator it =	users.begin();
	for (;it != users.end(); it++)
		std::cout << "[" << (*it)->nickname << "]" << std::endl;
}

void printMapOperators(Channel *chan)
{
	std::map<User *, bool>::iterator ope = chan->operators.begin();
	for (; ope != chan->operators.end(); ope++)
	{
		std::cout << "mapOperators :[" << ope->first->nickname << "]" << "[" << ope->second << "] [" << ope->first << "]" << std::endl;
	}
}
