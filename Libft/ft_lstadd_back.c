#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->num == new->num)
		{
			write(2, "Error\n", 6);
			lb(0, 0);
		}
		tmp = tmp -> next;
	}
	if (tmp->num == new->num)
	{
		write(2, "Error\n", 6);
		lb(0, 0);
	}
	tmp->next = new;
}
