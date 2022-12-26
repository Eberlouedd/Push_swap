/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:56:37 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/26 19:29:04 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**get_instruction(void)
{
	char	*buff;
	char	*str;
	char	**result;

	str = NULL;
	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		str = ft_strjoin(str, buff);
		free(buff);
		buff = NULL;
	}
	if (str)
	{
		result = ft_split(str, '\n');
		free(str);
		return (result);
	}
	return (ft_split("\n", ' '));
}

void	exit_error(t_list **stack_a, t_list **stack_b)
{
	write(1, "Error\n", 6);
	clear(stack_a);
	clear(stack_b);
}

int	match_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(str, "ss") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb") == 0)
		push(stack_b, stack_a);
	else if (!(ft_strcmp(str, "\n") == 0))
		return (exit_error(stack_a, stack_b), 0);
	return (1);
}

void	exe_instruction(t_list **stack_a, t_list **stack_b, char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (!match_instruction(stack_a, stack_b, instructions[i]))
		{
			free_double_char(instructions);
			exit(1);
		}
		i++;
	}
}

int	is_grinded(t_list *stack)
{
	int	before;

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
