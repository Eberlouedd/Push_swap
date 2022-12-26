
int is_empty(t_list stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	char **instructions;
	t_list *stack_a;
	t_list *stack_b;
	char **last;

	stack_b = NULL;
	if (!test_format(argc, argv))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	if (argc == 1)
		return (0);
	last = final_parsing(argc, argv);
	stack_a = create_stack_a(last);
	free_double_char(last);
	instructions = get_instruction();
	match_instruction(&stack_a, &stack_b, instructions);
	free_double_char(instructions);
	if(is_grinded(stack_a) && is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}