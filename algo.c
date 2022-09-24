
#include "push_swap.h"

void the_grading_machine(t_list **stack_a, t_list **stack_b, int med, int max)
{
	set_stack_b(stack_a, stack_b, med, max);
	move_max_btoa(stack_a, stack_b);
}

void    set_stack_b(t_list **stack_a, t_list **stack_b, int med, int max)
{
	int	i;

	i = 1;
	while (i <= ft_lstsize(*stack_a))
	{
		if (get_element(*stack_a, i) >= med && get_element(*stack_a, i) < max)
		{
			get_at_top(stack_a, get_element(*stack_a, i));
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i <= ft_lstsize(*stack_a))
	{
		if(get_element(*stack_a, i) != max)
		{
			get_at_top(stack_a, get_element(*stack_a, i));
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			i = 0;
		}
		i++;
	}
}

int	schr_max(t_list *stack)
{
	int	 max;
	int	index;
	int i;

	i = 1;
	index = 1;
	max = stack->content;
	while (stack)
	{
		if(stack->content > max)
		{
			index = i;
			max = stack->content;
		}	
		stack = stack->next;
		i++;
	}
	return (index);
}

void move_max_btoa(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;

	size = ft_lstsize(*stack_b);
	i = 1;
	while(i <= size)
	{
		get_at_top(stack_b, get_element(*stack_b, schr_max(*stack_b)));
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
		i++;
	}
}