/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:51:50 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/07 13:13:56 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_estim(long n)
{
	size_t	estim;

	estim = 0;
	if (n < 0)
	{
		estim++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*ft_gen(char *rtn, long nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
	{
		rtn = ft_strdup("0");
		return (rtn);
	}
	if (!rtn)
		return (0);
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_estim(nbr);
	rtn = 0;
	isneg = 0;
	rtn = ft_gen(rtn, nbr, len, isneg);
	if (!rtn)
		return (0);
	return (rtn);
}

static char	*treat_base(unsigned long long ull_str, int base,
char *rtn, int count)
{
	while (ull_str != 0)
	{
		if ((ull_str % base) < 10)
			rtn[count - 1] = (ull_str % base) + '0';
		else
			rtn[count - 1] = (ull_str % base) + ('A' - 10);
		ull_str /= base;
		count--;
	}
	return (rtn);
}

char	*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_str;
	int					count;

	rtn = 0;
	count = 0;
	ull_str = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	rtn = malloc(sizeof(char) * (count + 1));
	if (!rtn)
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_str, base, rtn, count);
	return (rtn);
}
