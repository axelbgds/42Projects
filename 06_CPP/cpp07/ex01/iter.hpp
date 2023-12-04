
#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *array, int length, void (*function)(T&)){
	for(int i = 0; i < length; i++)
		function(array[i]);};
		
template<typename T>
void	iter(T *array, int length, void (*function)(const T&)){
	for(int i = 0; i < length; i++)
		function(array[i]);};
		
#endif
