
#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
class Span
{
	private:
		Span();
		std::vector<int>	vect;
		unsigned int		_size;	
	public:
		Span(unsigned int i);
		~Span();
		Span(const Span& src);
		Span&	operator=(const Span src);
		void	addNumber(int i);
		void	addMore(std::vector<int> vecto);
		int		shortestSpan();
		int		longestSpan();
		std::vector<int>	getVect();
};

#endif
