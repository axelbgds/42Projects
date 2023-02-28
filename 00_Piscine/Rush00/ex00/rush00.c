/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazorla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:23:46 by jcazorla          #+#    #+#             */
/*   Updated: 2022/01/29 12:35:19 by jcazorla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	repeat(char c, int n)
{
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
}

void	body(int x, int y)
{
	while (y > 0)
	{
		ft_putchar('|');
		repeat(' ', x - 2);
		if (x != 1)
		{
			ft_putchar('|');
		}
		ft_putchar('\n');
		y--;
	}
}

void	limit(int x)
{
	ft_putchar('o');
	repeat('-', x - 2);
	if (x != 1)
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	limit(x);
	body(x, y - 2);
	if (y > 1)
	{
		limit(x);
	}
}
