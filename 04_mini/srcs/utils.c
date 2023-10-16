/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:30:11 by alsaez            #+#    #+#             */
/*   Updated: 2023/08/31 15:27:03 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*ft_sjf(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

int	ft_lenvar(char *varName)
{
	int	i;

	i = 0;
	while (varName[i] != '=' && varName[i] != '\0')
		i++;
	return (i);
}

int	ft_pludeplass(t_data *data, int i)
{
	char	**sp;

	if (!data->new_cmd[0])
		return (0);
	sp = ft_split(data->new_cmd, ' ');
	free(data->cmd[i]);
	data->cmd[i] = ft_strdup(sp[0]);
	free(data->full[i]);
	data->full[i] = ft_strdup(data->new_cmd);
	free(data->new_cmd);
	ft_freesplit(sp);
	if (!data->full[i][0])
		return (0);
	return (1);
}
