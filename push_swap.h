#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int	    check_str(char *str);
int	    test_format(int n, char **arg, int *med, int *max);
int	    strchr_num(char *str);
char	**final_parsing(int n, char **arg);
t_list *create_stack_a(char **str);
void    swap(t_list **stack, int n);
void    push(t_list **stack_dest, t_list **stack_src);
void    rotate(t_list **stack, int n);
void    reverse_rotate(t_list **stack, int n);
void    clear_first_element(t_list **stack);
t_list	*get_before_last(t_list *lst);
int	    strlen_double(char **str);
int     find_med(char **splited);
int     find_max(char **splited);
int     *tab_char_to_int(char **tab, int size);
void	sort_int_tab(int *tab, int size);
void    get_to_top_a(t_list **stack, int num);
void    get_to_top_b(t_list **stack, int num);
int     top_or_bot(t_list *stack, int n);
void    the_grading_machine(t_list **stack_a, t_list **stack_b, int med, int max);
void    set_stack_b(t_list **stack_a, t_list **stack_b, int med, int max);
void	afflist(t_list *list);
int     get_element(t_list *stack, int i);
int	    find_place(t_list *stack, int element);
int     count_moves(int len_a, int len_b, int index_a, int index_b);
void	from_b_to_a(t_list **stack_a, t_list **stack_b, int index_a, int index_b);
void    get_best_move(t_list *stack_a, t_list *stack_b, int *a, int *b);
void    grind_new_a(t_list **stack_a);
int	    get_first_min(t_list *stack, int element);
int	    is_grinded(t_list *stack);
void    clear_stacks(t_list **stack_a, t_list **stack_b);

#endif