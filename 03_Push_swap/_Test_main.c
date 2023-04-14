// #include <stdio.h>
// #include "push_swap.h"

// //is_empty_stack

// void print_stack(t_list *stack)
// {
// 	if(!stack)
// 	{
// 		printf("Rien a afficher, la pile est vide.\n");
// 		return;
// 	}

// 	while(stack)
// 	{
// 		printf("[%d]\n", stack->data);
// 		stack = stack->next;
// 	}
// }


// int main(void)
// {
//     t_list *stack = NULL;
//     t_list *node1 = ft_lstnew(42);
//     t_list *node2 = ft_lstnew(1337);
//     t_list *node3 = ft_lstnew(69);

//     ft_lstadd_back(&stack, node1);
//     ft_lstadd_back(&stack, node2);
//     ft_lstadd_back(&stack, node3);

//     printf("Stack avant rev_rot:\n");
//     ft_lstiter(stack, &print_stack);
//     rev_rot(&stack);

//     printf("Stack apres rev_rot:\n");
//     ft_lstiter(stack, &print_stack);
//     return(0);
// }