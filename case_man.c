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
    char *buff;

    num = ft_atoi(str);
    buff = ft_itoa(num);
    if (ft_strcmp(buff, str))
    {
        free(buff);
        return (0);
    }
    free(buff);
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

void clear(t_list **stack)
{
    int i;

    i = 0;
    while (i < ft_lstsize(*stack))
        clear_first_element(stack);
}

void	free_double_char(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}