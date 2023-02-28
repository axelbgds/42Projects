/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazorla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:11:30 by jcazorla          #+#    #+#             */
/*   Updated: 2022/01/29 13:29:08 by jcazorla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	up(int x);

void	down(int x);

void	body(int x, int y);

void	repeat(char c, int n)
{
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	up(x);
	body(x, y - 2);
	if (y > 1)
	{
		down(x);
	}
}

void	up(int x)
{
	ft_putchar('/');
	repeat('*', x - 2);
	if (x != 1)
	{
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	down(int x)
{
	ft_putchar('\\');
	repeat('*', x - 2);
	if (x != 1)
	{
		ft_putchar('/');
	}
	ft_putchar('\n');
}

void	body(int x, int y)
{
	while (y > 0)
	{
		ft_putchar('*');
		repeat(' ', x - 2);
		if (x != 1)
		{	
			ft_putchar('*');
		}
		ft_putchar('\n');
		y--;
	}
}
