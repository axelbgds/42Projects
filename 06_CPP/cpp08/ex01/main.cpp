
#include <sys/time.h>
#include "Span.hpp"

static long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 10 + tv.tv_usec / 10);
}

int	main(void)
{
	Span	test(10000);
	Span	test2(3);
	Span	test3(10);
	srand(time(NULL));
	for(unsigned int i = 0; i < 10010; i++)
		test.addNumber(rand()%100000);
	for(unsigned int i = 0; i < 5; i++)
		test2.addNumber(rand()%100000);
	test3.addNumber(1);
	try
	{std::cout << "Shortest Span : " << test.shortestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}
	try
	{std::cout << "Longest Span : " << test.longestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}
	try
	{std::cout << "Shortest Span 2 : " << test2.shortestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}
	try
	{std::cout << "Longest Span 2 : " << test2.longestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}
	try
	{std::cout << "Shortest Span 3 : " << test3.shortestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}
	try
	{std::cout << "Longest Span 3 : " << test3.longestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}
	try
	{test3.addMore(test2.getVect());}
	catch(const std::exception& e)
	{std::cout << " Can't add vector because of overflow" << std::endl;}
	try
	{test3.addMore(test2.getVect());}
	catch(const std::exception& e)
	{std::cout << " Can't add vector because of overflow" << std::endl;}
	try
	{test3.addMore(test2.getVect());}
	catch(const std::exception& e)
	{std::cout << " Can't add vector because of overflow" << std::endl;}
	try
	{test3.addMore(test2.getVect());}
	catch(const std::exception& e)
	{std::cout << " Can't add vector because of overflow" << std::endl;}
	try
	{std::cout << "Shortest Span 3 : " << test3.shortestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}
	try
	{std::cout << "Longest Span 3 : " << test3.longestSpan() << std::endl;}
	catch(const std::exception& e)
	{std::cout << "Not enough element to call the function" << std::endl;}	
}

