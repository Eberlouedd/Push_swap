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

int test_limit(char *str)
{
    int num;

    num = ft_atoi(str);
    if (ft_strcmp(ft_itoa(num), str))
        return (0);
    return (1);
}

int find_min(t_list *stack)
{
    int min;

    min = stack->content;
    while(stack)
    {
        if(stack->content < min)
            min = stack->content;
        stack = stack->next;
    }
    return (min);
}
