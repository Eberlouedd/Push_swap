#include "push_swap.h"

void	afflist(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->content);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	int	med;
	int max;

	if (!test_format(argc, argv, &med, &max) || argc == 1)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	stack_a = create_stack_a(final_parsing(argc, argv));
	the_grading_machine(&stack_a, &stack_b, med, max);
	return (0);
}