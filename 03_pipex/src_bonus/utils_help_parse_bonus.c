

#include <pipex_bonus.h>

/* remove outermost " | ' pair, return clear string */
char	*ft_clearstr(char *str, int *pos)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i != pos[0] && i != pos[1])
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (tmp);
}

/* localize outermost " | ' pair, return clear string */
char	*ft_nest(char *str)
{
	int	i;
	int	foundfirst;
	int	pos[2];

	foundfirst = 0;
	i = 0;
	while (str[i])
	{
		if (!foundfirst && (str[i] == '\'' || str[i] == '\"'))
		{
			pos[0] = i;
			foundfirst = 1;
		}
		if (str[i] == '\'' || str[i] == '\"')
			pos[1] = i;
		i++;
	}
	return (ft_clearstr(str, pos));
}

/* get lengths of two splits */
void	ft_lengths(char *str, int *len)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
		{
			len[0] = i;
			len[1] = ft_strlen(str) - i;
			break ;
		}
		i++;
	}
}

/* return 0 terminated char ** splitting on 1st space only */
char	**ft_cond_split(char *str)
{
	int		len[2];
	char	**arr;

	ft_lengths(str, len);
	arr = ft_calloc(3, sizeof(char *));
	arr[0] = ft_substr(str, 0, len[0]);
	arr[1] = ft_substr(str, len[0] + 1, len[1]);
	arr[2] = NULL;
	return (arr);
}

/* return 1 if space precedes 1st / */
int	ft_prevsp(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '/')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
