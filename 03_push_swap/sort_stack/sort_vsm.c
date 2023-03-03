/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vsmall_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:49:26 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 15:39:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_vsm_stack(t_stack **A, t_stack **B)
{
	if((*A)->next == NULL || (*A)->next->next == NULL)
		return ;
	if ((*A)->data > (*A)->next->data)
		sa(A);
}
