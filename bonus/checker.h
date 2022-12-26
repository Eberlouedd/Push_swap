/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:54:38 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/26 17:58:16 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		is_empty(t_list *stack);
void	swap(t_list **stack);
void	push(t_list **stack_dest, t_list **stack_src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		strchr_num(char *str);
int		check_str(char *str);
int		check_doublon(char **str);
int		test_format(int n, char **arg);
char	**final_parsing(int n, char **arg);
t_list	*get_before_last(t_list *lst);
t_list	*create_stack_a(char **str);
void	clear_first_element(t_list **stack);
void	free_double_char(char	**str);
int		test_limit(char *str);
int		is_grinded(t_list *stack);
int		match_instruction(t_list **stack_a, t_list **stack_b, char *str);
char	**get_instruction(void);
void	exe_instruction(t_list **stack_a, t_list **stack_b,
			char **instructions);
void	clear(t_list **stack);

#endif