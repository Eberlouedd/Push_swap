#include "push_swap.h"

void	afflist(t_list *stack)
{
	while(stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	//t_list *stack_a;
	//t_list *stack_b;
	int	med;
	int max;

	//stack_b = NULL;
	if (!test_format(argc, argv, &med, &max) || argc == 1)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	/*stack_a = create_stack_a(final_parsing(argc, argv));
	if(!is_grinded(stack_a))
		the_grading_machine(&stack_a, &stack_b, med, max);
	clear(&stack_a);*/
	return (0);
}