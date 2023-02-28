/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 07:03:39 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/03 15:12:48 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_spaces(char *str)
{
	while (
		str[0] == '\t'
		|| str[0] == '\n'
		|| str[0] == '\v'
		|| str[0] == '\f'
		|| str[0] == '\r'
		|| str[0] == ' '
	)
		str++;
	return (str);
}

char	*get_sign(char *str, int *sign)
{
	sign[0] = 1;
	while (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign[0] *= -1;
		str++;
	}
	return (str);
}

char	*count_digits(char *str, int *count)
{
	while (str[0] >= '0' && str[0] <= '9')
	{
		str++;
		count[0]++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	size;
	int	mult;
	int	rtn;

	rtn = 0;
	mult = 1;
	str = skip_spaces(str);
	str = get_sign(str, &sign);
	str = count_digits(str, &size) - 1;
	while (size > 0)
	{
		rtn += (str[0] - '0') * mult;
		mult *= 10;
		str--;
		size--;
	}
	return (rtn * sign);
}
