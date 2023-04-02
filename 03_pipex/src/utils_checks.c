

#include <pipex.h>

/* return count of " or ' */
int	ft_chkquotes(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			count++;
		i++;
	}
	return (count);
}

/* return 1 if some quotations are escaped */
int	ft_chkqmesc(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (i > 0 && str[i - 1] == '\\')
				return (1);
		}
		i++;
	}
	return (0);
}

/* return char * removing dbl escape totally */
char	*ft_remdblesc(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_calloc(ft_strlen(str) + 1, 1);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (str[i] == '\\' && str[i + 1] && str[i + 1] == '\\')
		i += 2;
		else
		{
			tmp[j] = str[i];
			i++;
			j++;
		}
	}
	free(str);
	return (tmp);
}

/* return char * maanging several sorts of prasings (\. '. "...)*/
void	ft_mgexcept(t_data *d)
{
	int		i;
	char	*str;

	i = 0;
	while (i < d->cnum)
	{
		str = ft_strdup(d->argv[i + 2]);
		if (ft_chkquotes(str) > 1)
		{
			if (!ft_chkqmesc(str))
				str = ft_nest(str);
			else
			{
				str = ft_remdblesc(str);
				str = ft_nest(str);
				d->args[i] = ft_split(str, '\0');
			}
			d->args[i] = ft_cond_split(str);
		}
		else
			d->args[i] = ft_split(str, ' ');
		free(str);
		i++;
	}
}
