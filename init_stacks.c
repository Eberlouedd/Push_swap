#include "push_swap.h"

t_list *create_stack_a(char **str)
{
    t_list *stack;
    int i;

    i = 1;
    stack = ft_lstnew(ft_atoi(str[0]));
    while(str[i])
    {
        ft_lstadd_back(&stack, ft_lstnew(ft_atoi(str[i])));
        i++;
    }
    return (stack);
}

void    clear_first_element(t_list **stack)
{
    t_list  *buff;

    buff = (*stack)->next;
    free(*stack);
    *stack = buff;
}

t_list	*get_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void    get_best_move(t_list *stack_a, t_list *stack_b, int *a, int *b)
{
    int i;
    int moves;
    int final;
    int before;

    i = 1;
    while (i <= ft_lstsize(stack_b))
    {
        *a = find_place(stack_a, get_element(stack_b, i));
        printf("b : %d, a : %d", i, *a);
        moves = count_moves(ft_lstsize(stack_a), ft_lstsize(stack_b), *a, i);
        printf("%d\n", moves);
        if(moves < before)
        {
            final = i;
            before = moves;
        }
        i++;
    }
    *b = final;
    printf("\n%d\n", *b);
    *a = find_place(stack_a, get_element(stack_b, *b));
}

void    grind_new_a(t_list **stack_a)
{
    int i;
    int final;
    int before;

    i = 1;
    before = get_element(*stack_a, 1);
    while (i <= ft_lstsize(*stack_a))
    {
        if (get_element(*stack_a, i) > before)
        {
            final = i;
            before = get_element(*stack_a, i);
        }
        i++;
    }
    if(final == 3 && get_element(*stack_a, 1) < get_element(*stack_a, 2))
        return ;
    if (final == 1)
       rotate(stack_a, 1);
    else if (final == 2)
        reverse_rotate(stack_a, 1);
    if(get_element(*stack_a, 1) > get_element(*stack_a, 2))
        swap(stack_a, 1);
}