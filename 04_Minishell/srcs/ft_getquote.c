/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getquote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:52:22 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/31 12:32:13 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

char	*ft_getquote(t_data *data, int i, int j)
{
	char	*res;
	int		k;

	k = j + 1;
	if (data->full[i][k] == ' ' || data->full[i][k] == '"'
	|| !data->full[i][k])
		return (ft_strdup("$"));
	while (data->full[i][j] != ' ' && data->full[i][j])
		j++;
	res = malloc(j - k + 2);
	j = 0;
	while (data->full[i][k] != ' ' && data->full[i][k] != '"'
		&& data->full[i][k] != '\'' && data->full[i][k])
		res[j++] = data->full[i][k++];
	res[j] = '\0';
	j = 0;
	while (data->env_cpy[j])
	{
		if (!ft_strncmp(data->env_cpy[j], res, ft_strlen(res)))
			return (ft_get_arg(data, j, res));
		j++;
	}
	if (res)
		free(res);
	return (ft_calloc(1, 1));
}

char	*ft_get_arg(t_data *data, int j, char *res)
{
	int	k;
	int	l;

	k = 0;
	while (data->env_cpy[j][k] != '=')
		k++;
	l = ++k;
	if (data->env_cpy[j][k])
	{
		while (data->env_cpy[j][k])
			k++;
		free(res);
		res = malloc(k - l + 1);
		k = 0;
		while (data->env_cpy[j][l])
		{
			res[k] = data->env_cpy[j][l];
			k++;
			l++;
		}
		res[k] = '\0';
		return (res);
	}
	return (NULL);
}
