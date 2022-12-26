#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int is_empty(t_list stack);
void    swap(t_list **stack);
void    push(t_list **stack_dest, t_list **stack_src);
void    rotate(t_list **stack);
void    reverse_rotate(t_list **stack);
void ss(t_list **stack_a, t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
int	strchr_num(char *str);
int	check_str(char *str);
int	check_doublon(char **str);
int	test_format(int n, char **arg);
char	**final_parsing(int n, char **arg);

#endif