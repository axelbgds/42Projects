/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:14 by abeaugra          #+#    #+#             */
/*   Updated: 2023/12/21 16:15:58 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <ctime>
# include <algorithm>

class PmergeMe
{
    public:

        PmergeMe();
        PmergeMe(PmergeMe const &p);
        PmergeMe    &operator=(PmergeMe const &);
        ~PmergeMe();
        void    mergeInsertSort(std::vector<int> &vector);
};

#endif


