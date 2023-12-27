/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 16:16:19 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
    if (ac != 1) {
        std::vector<int> data;
        try 
		{
			int	i = 1;
            while (i < ac) 
			{
                int num = atoi(av[i]);
                if (num >= 0) 
				{
                    data.push_back(num);
                } 
				else 
				{
                    std::cerr << "Error: Entiers négatifs ne sont pas autorisés." << std::endl;
                    return (1);
                }
				i++;
            }
        } 
		catch (const std::exception& e) 
		{
            std::cerr << "Error" << std::endl;
            return (1);
        }

        std::cout << "Before: ";
		size_t	i = 0;
        while (i < data.size())
            std::cout << data[i++] << " ";
        std::cout << std::endl;

        std::vector<int> data_copy = data;
		PmergeMe	pmergeme;
		
        clock_t start_time = clock();
        pmergeme.mergeInsertSort(data);
        clock_t end_time = clock();
        double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        std::cout << "After: ";
		i = 0;
        while (i < data.size()) 
            std::cout << data[i++] << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << data.size() << " elements with mergeInsertSort: " << duration * 1000000 << " us" << std::endl;

        start_time = clock();
        std::list<int> dataList(data_copy.begin(), data_copy.end());
        dataList.sort();
        data_copy.assign(dataList.begin(), dataList.end());
        end_time = clock();
        duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << data_copy.size() << " elements with std::list::sort: " << duration * 1000000 << " us" << std::endl;

        return (0);
    } 
	else 
	{
        std::cerr << "Usage: " << av[0] << " <sequence of positive integers separated by spaces>" << std::endl;
        return (1);
    }
}