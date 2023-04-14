/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:49:08 by abeaugra          #+#    #+#             */
/*   Updated: 2022/04/22 15:06:47 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>

// int strlen => le NULL de la fin ne comptera pas
// parcourir la liste pourafficher la liste char strlen

// %c Affiche un seul caractère. = isalpha
// %s Affiche une chaîne de caractères (telle que définie par la convention C). 
// %d Affiche un nombre décimal (base 10).
// %i Affiche un entier en base 10.
// %u Affiche un nombre décimal non signé (base 10).
// %p L’argument de pointeur void * doit être affiché en hexadécimal.
// %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
// %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
// %% Affiche un signe pourcentage

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	checks(char *s1)
{
	int	i;
		i = 0;
	while (s1[i])
	{
		write(1, &s1[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd) //renvoyer un len sur size_t en static
{
	fd = 1;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd (n + '0', fd);
	}
}

size_t	 nbr_hex(unsigned long nb, int up_case, int pxx)
{
	size_t	len;
	char	*base;
	
	len = 0;
	if (pxx)
		len += write(1, "0x", 2);
	if (up_case)
		base = "0123456789ABCDEF";
	if (!up_case)
		base = "0123456789abcdef";
	if (nb > 15)
		len += nbr_hex((nb / 16), up_case, 0);
	len += write(1, &base[nb% 16], 1);
	return (len);
}

static size_t	putnbr_len(long long nb)
{
	size_t				len;
	unsigned long long	n;

	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
		len++;
	}
	else
		n = nb;
	if (n > 9)
		len += putnbr_len(n / 10);
	n = (n % 10) + 48;
	len += write(1, &n, 1);
	return (len);
}

int ft_printf(const char *s1, ...)
{
	int i;
	va_list arguments;

	char c = 0;
	va_start(arguments,s1);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == '%')
		{
			if (s1[i + 1] == 's')
				checks(va_arg(arguments,char *));
			else if (s1[i + 1] == 'c')
			{
				c = va_arg(arguments, int);
				write(1,&c,1);
			}
			else if (s1[i + 1] == 'd' || s1[i + 1] == 'i' ) 
				putnbr_len(va_arg(arguments, int));
			else if (s1[i +1 ] == 'u')
				putnbr_len(va_arg(arguments, unsigned int));
			else if (s1[i + 1] == 'p')
				nbr_hex(va_arg(arguments, unsigned long), 0, 1);
			else if (s1[i + 1] == 'x')
				nbr_hex(va_arg(arguments, unsigned long), 0, 0);
			else if (s1[i + 1] == 'X')
				nbr_hex(va_arg(arguments, unsigned long), 1, 0);
			else if ((s1[i + 1] == '%'))
				write(1, "%", 1);
			i++;
		}
		else 
		ft_putchar_fd(s1[i], 1);
		i++;
	}
	va_end(arguments);
	return(0);
}

int main()
{
	char ptr[] = "coucou toto";
	char *toto = "toto";
	ft_printf	("test %s %s   salut\n",ptr,toto);
	printf		("test %s %s  salut\n",ptr,toto);
	return (0);
}
