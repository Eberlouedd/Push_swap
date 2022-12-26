#include "checker.h"

void	free_double_char(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int is_empty(t_list *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

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
    //free_double_char(str);
    return (stack);
}

void    clear_first_element(t_list **stack)
{
    t_list  *buff;

    buff = (*stack)->next;
    free(*stack);
    *stack = buff;
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