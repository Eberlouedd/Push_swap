#include "push_swap.h"

void    swap(t_list **stack, int n)
{
    int tmp;

    if(stack == NULL || (*stack)->next == NULL)
        return ;
    tmp = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = tmp;
    if (!n)
        write(1, "sb\n", 3);
    else
        write(1, "sa\n", 3);
}

void    push(t_list **stack_dest, t_list **stack_src, int n)
{
    if(stack_src == NULL)
        return ;
    ft_lstadd_front(stack_dest, ft_lstnew((*stack_src)->content));
    clear_first_element(stack_src);
    if (!n)
        write(1, "pb\n", 3);
    else
        write(1, "pa\n", 3);
}

void    rotate(t_list **stack, int n)
{
    int tmp;

    tmp = (*stack)->content;
    clear_first_element(stack);
    ft_lstadd_back(stack, ft_lstnew(tmp));
    if (!n)
        write(1, "rb\n", 3);
    else
        write(1, "ra\n", 3);
}

void    reverse_rotate(t_list **stack, int n)
{
    int tmp;
    t_list *tmp2;

    tmp = ft_lstlast(*stack)->content;
    ft_lstadd_front(stack, ft_lstnew(tmp));
    tmp2 = ft_lstlast(*stack);
    get_before_last(*stack)->next = NULL;
    free(tmp2);
    if (!n)
        write(1, "rrb\n", 4);
    else
        write(1, "rra\n", 4);
}
