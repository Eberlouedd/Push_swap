#include "push_swap.h"

int	is_grinded(t_list *stack)
{
    int before;

    before = stack->content;
    stack = stack->next;
	while (stack)
    {
        if (stack->content < before)
            return (0);
        before = stack->content;
        stack = stack->next;
    }
    return (1);
}

void    clear_stacks(t_list **stack_a, t_list **stack_b)
{
    while(stack_a)
        clear_first_element(stack_a);
    while(stack_b)
        clear_first_element(stack_b);
}