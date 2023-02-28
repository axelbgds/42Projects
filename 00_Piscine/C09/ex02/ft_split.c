/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:46:01 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/15 16:05:41 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

int	is_in_charset(char c, char *charset)
{
	while (charset[0])
	{
		if (c == charset[0])
			return (1);
		charset++;
	}
	return (0);
}

int	get_size(char *str, char *charset)
{
	int	count;

	count = 0;
	str++;
	while (str[0])
	{
		if (count == 0 && (is_in_charset(str[0], charset)))
			count = 1;
		if (
			is_in_charset(str[0], charset)
			&& (is_in_charset(str[1], charset) == 0)
		)
			count++;
		str++;
	}
	if (is_in_charset(str[-1], charset))
		count--;
	return (count);
}

char	*skip_and_count(char *str, int *s, char *charset)
{
	s[0] = 0;
	while (is_in_charset(str[0], charset))
			str++;
	while (
		str[0]
		&& (is_in_charset(str[0], charset) == 0)
	)
	{
		str++;
		s[0]++;
	}
	return (str);
}

void	cpy(int seg_size, int seg_initial_size,
			char *out, char *str)
{
	out[seg_size] = 0;
	while (seg_size > 0)
	{
		out[seg_initial_size - seg_size] = str[-seg_size];
		seg_size--;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		seg_size;
	int		seg_initial_size;
	char	**ret;

	ret = malloc((get_size(str, charset) + 1) * sizeof(*ret));
	if (ret == 0)
		return (0);
	i = 0;
	while (1)
	{
		str = skip_and_count(str, &seg_size, charset);
		if (!seg_size)
			break ;
		seg_initial_size = seg_size;
		ret[i] = malloc(seg_size + 1);
		if (ret[i] == 0)
			return (0);
		cpy(seg_size, seg_initial_size, ret[i], str);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int i = 0;
	char **ret;

	if (argc != 3) {
		// ./a.out <text> <charset>
		return 1;
	}

	ret = ft_split(argv[1], argv[2]);
	
	if (ret == 0) {
		perror("ft_split");
		return 1;
	}

	while (ret[i]) {
		printf("%d: %s\n", i, ret[i]);
		i++;
	}

	return 0;
}*/
