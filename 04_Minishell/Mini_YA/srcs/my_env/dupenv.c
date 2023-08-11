#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_env
{
	char			*variable;
	char			*value;
	int				print;
	struct s_env	*next;
}					t_env;

t_env	*newenv(char *variable, char *value, int prenv)
{
	t_env	*node;

	node = malloc(sizeof (t_env));
	if (!node)
		return (NULL);
	node -> variable = variable;
	node -> value = value;
	node -> print = prenv;
	node -> next = NULL;
	return (node);
}

char	*dup_alloc(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*sub_malloc(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s + start);
	if (len > slen)
		len = slen;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	slen = ft_strlen(s);
	i = -1;
	while (++i < len && start[s] && start < slen)
		*(str + i) = *(s + start + i);
	str[i] = '\0';
	return (str);
}

char	*itoa_allo(int n)
{
	int			i;
	long int	nb;
	char		*str;

	if (n == 0)
		return (dup_alloc("0"));
	i = count(n);
	nb = n;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (str);
	str[i] = '\0';
	if (n < 0)
		nb = nb * (-1);
	while (--i >= 0)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

void	addbenv(t_env **lst, t_env *new)
{
	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

char	**subbing(char *env)
{
	int		i;
	char	**varandval;

	i = -1;
	while (env[++i])
		if (env[i] == '=')
			break ;
	varandval = malloc(sizeof(char *) * 3);
	if (!varandval)
		return (NULL);
	varandval[0] = sub_malloc(env, 0, i);
	if (ft_strchr(env, '='))
		varandval[1] = sub_malloc(env, i + 1, ft_strlen(env + i));
	else
		varandval[1] = dup_alloc("");
	varandval[2] = NULL;
	if (!ft_memcmp("SHLVL", varandval[0], 6))
	{
		i = ft_atoi(varandval[1]);
		(i >= 0) && (i++);
		(i < 0) && (i = 0);
		free(varandval[1]);
		varandval[1] = itoa_a(i);
	}
	return (varandval);
}

void	dupenv(t_env **myenv, char **env)
{
	int		i;
	char	**subenv;

	i = -1;
	*myenv = NULL;
	if (!env[0])
		return (addbenv(myenv, newenv(dup_alloc("PWD"), getcwd(NULL, 0), 1)),
			addbenv(myenv, newenv(dup_alloc("SHLVL"), dup_alloc("1"), 1)),
			addbenv(myenv, newenv(dup_alloc("PATH"),
					dup_alloc(_PATH_STDPATH), 1)));
	while (env[++i])
	{
		subenv = subbing(env[i]);
		addbenv(myenv, newenv(subenv[0], subenv[1], 1));
		free(subenv);
	}
}

int main() {
    char *env[] = {
        "USER=john",
        "HOME=/home/john",
        "SHELL=/bin/bash",
        NULL // Le tableau se termine par NULL
    };

    t_env *myenv;
    dupenv(&myenv, env);
    t_env *A = myenv;
    while (A != NULL) {
        printf("Variable: %s, Value: %s\n", A->variable, A->value);
        A = A->next;
    }
    return 0;
}
