/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:48:37 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/16 11:17:48 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

int	main(int argc, char **argv)
{
	int	i;
	int	ret;

	if (argc < 2)
		return cat_file("-");
	i = 1;
	ret = 0;
	while (i < argc)
	{
		ret |= cat_file(argv[i]);	
		i++;
	}
	return (ret);
}
