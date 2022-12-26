

char **get_instruction()
{
	char	*buff;
	while(instruction)
	{
		buff = get_next_line(0);
		str = ft_strjoin(str, buff);
	}
	return (ft_split(str, '\n'));
}

void match_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if(ft_strcmp(instruction[i], "ra") == 0)
			rotate(stack_a);
	else if(ft_strcmp(instruction[i], "rb") == 0)
		rotate(stack_b);
	else if(ft_strcmp(instruction[i], "rr") == 0)
		rr(stack_a, stack_b);
	else if(ft_strcmp(instruction[i], "rra") == 0)
		reverse_rotate(stack_a);
	else if(ft_strcmp(instruction[i], "rrb") == 0)
		reverse_rotate(stack_a);
	else if(ft_strcmp(instruction[i], "rrr") == 0)
		rrr(stack_a, stack_b);
	else if(ft_strcmp(instruction[i], "sa") == 0)
		swap(stack_a);
	else if(ft_strcmp(instruction[i], "sb") == 0)
		swap(stack_b);
	else if(ft_strcmp(instruction[i], "ss") == 0)
		ss(stack_a, stack_b);
	else if(ft_strcmp(instruction[i], "pa") == 0)
		push(stack_a, stack_b);
	else if(ft_strcmp(instruction[i], "pb") == 0)
		push(stack_b, stack_a);
}

void exe_instruction(t_list **stack_a, t_list **stack_b, char **instructions)
{
	int	i;

	i = 0;
	while(instructions[i])
	{
		match_instruction(stack_a, stack_b, instructions[i]);
		i++;
	}
}

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
