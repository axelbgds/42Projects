/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:49:26 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 15:39:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int argc, char **argv)
// {
//     t_stack A;
//     t_stack B;
//     int i;

//     if (argc < 2)
//         return 0;
//     stack_init(&A, argc - 1);
//     stack_init(&B, argc - 1);
//     i = 1;
//     while (i < argc)
//     {
//         if (!is_valid_number(argv[i]))
//         {
//             ft_putstr_fd("Error\n", 2);
//             return 1;
//         }
//         if (is_duplicate_number(A, ft_atoi(argv[i])))
//         {
//             ft_putstr_fd("Error\n", 2);
//             return 1;
//         }
//         stack_push(&A, ft_atoi(argv[i]));
//         i++;
//     }
//     if (A_is_sorted(&A))
//         return 0;
//     if (A->top <= 5)
//         sort_small_stack(&A, &B);
//     else
//         sort_big_stack(&A, &B);
//     stack_clear(&A);
//     stack_clear(&B);
//     return 0;
// }