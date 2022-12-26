/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:58:39 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/26 19:22:10 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	**instructions;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**last;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!test_format(argc, argv))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	last = final_parsing(argc, argv);
	stack_a = create_stack_a(last);
	free_double_char(last);
	instructions = get_instruction();
	exe_instruction(&stack_a, &stack_b, instructions);
	if (is_grinded(stack_a) && is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear(&stack_a);
	clear(&stack_b);
	return (free_double_char(instructions), 0);
}
