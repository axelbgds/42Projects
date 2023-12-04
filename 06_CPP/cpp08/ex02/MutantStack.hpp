
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>


template<typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
	    typedef                 std::stack<T> stack;
        typedef typename        stack::container_type container;
        typedef typename        container::iterator iterator;
		typedef typename        container::const_iterator const_iterator;
		MutantStack() : stack(){}
        MutantStack(const stack &src) : stack(src){}
        ~MutantStack(){}
        stack &operator=(const stack &src)
        {
            if (*this != src)
            	*this = src;
            return (*this);
        }                                                                                                      
        iterator begin(){return (stack::c.begin());}                                                                                                                  
        iterator end(){return (stack::c.end());}

};

#endif
