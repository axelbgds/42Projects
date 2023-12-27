/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 16:16:08 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(PmergeMe const &p)
{
    *this = p;
}

PmergeMe    &PmergeMe::operator=(PmergeMe const &)
{
    return (*this);
}

PmergeMe::~PmergeMe()
{

}

void    PmergeMe::mergeInsertSort(std::vector<int> &vector)
{
    if (vector.size() <= 1)
    {
        return ;
    }

    size_t  middle = vector.size() / 2;
    std::vector<int>    left(vector.begin(), vector.begin() + middle);
    std::vector<int>    right(vector.begin() + middle, vector.end());
    mergeInsertSort(left);
    mergeInsertSort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), vector.begin());
}