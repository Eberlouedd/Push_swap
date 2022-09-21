#include "push_swap.h"

t_list *create_stack_a(char **str)
{
    t_list *stack;
    int i;

    i = 1;
    stack = ft_lstnew(ft_atoi(str[0]));
    while(str[i])
    {
        ft_lstadd_back(&stack, ft_lstnew(ft_atoi(str[i])));
        i++;
    }
    return (stack);
}

void    clear_first_element(t_list **stack)
{
    t_list  *buff;

    buff = (*stack)->next;
    free(*stack);
    *stack = buff;
}

t_list	*get_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}