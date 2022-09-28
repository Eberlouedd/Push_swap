#include "push_swap.h"

void	get_to_top_a(t_list **stack, int num)
{
	if (top_or_bot(*stack, num))
	{
		while ((*stack)->content != num)
			rotate(stack, 1);
	}
	else
	{
		while ((*stack)->content != num)
			reverse_rotate(stack, 1);
	}
}

int	top_or_bot(t_list *stack, int n)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == n)
			break ;
		stack = stack->next;
		i++;
	}
	if (ft_lstsize(stack) - i >= ft_lstsize(stack) / 2)
		return (1);
	else
		return (0);
}

void	get_to_top_b(t_list **stack, int num)
{
	if (top_or_bot(*stack, num))
	{
		while ((*stack)->content != num)
			rotate(stack, 0);
	}
	else
	{
		while ((*stack)->content != num)
			reverse_rotate(stack, 0);
	}
}

int	get_element(t_list *stack, int i)
{
	if (!stack)
		return (0);
	while (i > 1)
	{
		stack = stack->next;
		i--;
	}
	return (stack->content);
}
