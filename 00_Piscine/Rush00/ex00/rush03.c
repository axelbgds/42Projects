/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazorla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:11:30 by jcazorla          #+#    #+#             */
/*   Updated: 2022/01/29 15:14:57 by jcazorla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	line(int x, char *charset);

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
	line(x, "ABC");
	body(x, y - 2);
	if (y > 1)
	{
		line(x, "ABC");
	}
}

void	line(int x, char *charset)
{
	ft_putchar(charset[0]);
	repeat(charset[1], x - 2);
	if (x != 1)
	{
		ft_putchar(charset[2]);
	}
	ft_putchar('\n');
}

void	body(int x, int y)
{
	while (y > 0)
	{
		line(x, "B B");
		y--;
	}
}
