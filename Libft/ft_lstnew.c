#include"libft.h"

t_list	*ft_lstnew(int num, void *address)
{
	t_list	*node;

	node = lb(sizeof (t_list), 1);
	if (!node)
		return (NULL);
	node -> address = address;
	node -> num = num;
	node -> next = NULL;
	return (node);
}
