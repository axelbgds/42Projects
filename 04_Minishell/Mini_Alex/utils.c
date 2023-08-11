/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:30:11 by jcasades          #+#    #+#             */
/*   Updated: 2023/07/05 11:06:13 by jcasades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_lenvar(char *varName)
{
	int	i;

	i = 0;
	while (varName[i] != '=' && varName[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoinc(char *s1, char s2)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (strlen(s1) + 2));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s2;
	i++;
	str[i] = '\0';
	free(s1);
	return (str);
}

void	ft_pludeplass(t_data *data, int i)
{
	free(data->full[i]);
	data->full[i] = ft_strdup(data->new_cmd);
	free(data->new_cmd);
}
