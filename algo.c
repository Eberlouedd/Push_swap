#include "push_swap.h"

void the_grading_machine(t_list **stack_a, t_list **stack_b, int med, int max)
{
	int index_a;
	int index_b;
	int	i;
	int	size;

	i = 1;
	set_stack_b(stack_a, stack_b, med, max);
	grind_new_a(stack_a);
	size = ft_lstsize(*stack_b);
	while (i <= size)
	{
		get_best_move(*stack_a, *stack_b, &index_a, &index_b);
		from_b_to_a(stack_a, stack_b, index_a, index_b);
		i++;
	}
	if(!is_grinded(*stack_a))
		get_to_top_a(stack_a, find_min(*stack_a));
}

void    set_stack_b(t_list **stack_a, t_list **stack_b, int med, int max)
{
	int	i;

	i = 1;
	if (ft_lstsize(*stack_a) > 5)
	{
		while (i <= ft_lstsize(*stack_a) && ft_lstsize(*stack_a) > 3)
		{
			if (get_element(*stack_a, i) <= med && get_element(*stack_a, i) < max)
			{
				get_to_top_a(stack_a, get_element(*stack_a, i));
				push(stack_b, stack_a);
				write(1, "pb\n", 3);
				i = 0;
			}
			i++;
		}
	}
	i = 1;
	while (ft_lstsize(*stack_a) > 3)
	{
		if(get_element(*stack_a, i) != max)
		{
			get_to_top_a(stack_a, get_element(*stack_a, i));
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
			i = 0;
		}
		i++;
	}
}

int	find_place(t_list *stack, int element)
{
	int	min_of_max;
	int	i;
	int	final;

	i = 1;
	final = 1;
	min_of_max = get_first_min(stack, element);
	while(stack)
	{
		if(element < stack->content && min_of_max >= stack->content)
		{
			min_of_max = stack->content;
			final = i;
		}
		stack = stack->next;
		i++;
	}
	return (final);
}

int count_moves(int len_a, int len_b, int index_a, int index_b)
{
	int moves;
	
	moves = 1;
	if (len_b - index_b >= len_b / 2 && index_b != 1)
		moves += index_b - 1;
	else if (index_b != 1)
		moves += len_b - index_b + 1;
	if (len_a - index_a >= len_a / 2 && index_a != 1)
		moves += index_a - 1;
	else if (index_a != 1)
		moves += len_a - index_a + 1;
	return (moves);
}

void	from_b_to_a(t_list **stack_a, t_list **stack_b, int index_a, int index_b)
{
	get_to_top_a(stack_a, get_element(*stack_a, index_a));
	get_to_top_b(stack_b, get_element(*stack_b, index_b));
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}