
#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int i) : _size(i){}

Span::~Span(){}

Span::Span(const Span& src){
	vect = src.vect;
	*this = src;}


Span&	Span::operator=(const Span src){
	vect = src.vect;
	return (*this);}

void	Span::addNumber(int number)
{
	if (vect.size() < _size)
		{vect.push_back(number);}
	else
		std::cout << "Error, can't add " << number << " in the array" << std::endl;
}

void	Span::addMore(std::vector<int> vecto)
{
	if (vect.size() + vecto.size() > _size)
		throw(std::exception());
	else
		vect.insert(vect.end(), vecto.begin(), vecto.end());
}

int		Span::longestSpan()
{
	unsigned int i = 0;
	if (vect.size() > 1)
	{
		for (i < vect.size() && vect.at(i); i++;);
		std::sort(vect.begin(), vect.end());
		return(std::max(*vect.end() - *vect.begin(), *vect.end() + *vect.begin()));
	}
	throw(std::exception());
	return (0);
}

int		Span::shortestSpan()
{
	if (vect.size() > 1)
	{
		unsigned int i = 0;
		std::vector<int>::iterator	it = vect.begin();
		std::sort(vect.begin(), vect.end());
		i = *(it + 1 ) - *it;
		while(it + 1 != vect.end())
		{
			if (*(it + 1 ) - *(it) < i)
				i = *(it + 1 ) - *it;
			it++;
		}
		return (i);
	}
	throw(std::exception());
	return (0);
}

std::vector<int>	Span::getVect()
{return vect;}
