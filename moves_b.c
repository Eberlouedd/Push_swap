#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
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
	if (ft_lstsize(stack) - i > ft_lstsize(stack) / 2)
		return (1);
	else
		return (0);
}

void	get_at_top(t_list **stack, int num)
{
	if (top_or_bot(*stack, num))
	{
		while ((*stack)->content != num)
		{
			rotate(stack);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while ((*stack)->content != num)
		{
			reverse_rotate(stack);
			write(1, "rra\n", 4);
		}
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
