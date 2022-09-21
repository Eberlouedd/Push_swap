
#include "push_swap.h"

void the_grading_machine(t_list **stack_a, t_list **stack_b, int med, int max)
{
	set_stack_b(stack_a, stack_b, med, max);
}

void    set_stack_b(t_list **stack_a, t_list **stack_b, int med, int max)
{
	int	i;

	i = 1;
	while(i <= ft_lstsize(*stack_a))
	{
		if(get_element(*stack_a, i) >= med && get_element(*stack_a, i) < max)
		{
			get_at_top(stack_a, get_element(*stack_a, i));
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			i = 0;
		}
		i++;
	}
}