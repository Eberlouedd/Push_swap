#include "push_swap.h"

void    swap(t_list **stack)
{
    int tmp;

    if(stack == NULL || (*stack)->next == NULL)
        return ;
    tmp = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = tmp;
}

void    push(t_list **stack_dest, t_list **stack_src)
{
    t_list  *buff;
    if(stack_src == NULL)
        return ;
    buff = (*stack_src)->next;
    ft_lstadd_front(stack_dest, *stack_src);
    *stack_src = buff;
}

void    rotate(t_list **stack)
{
    int tmp;

    tmp = (*stack)->content;
    clear_first_element(stack);
    ft_lstadd_back(stack, ft_lstnew(tmp));
}

void    reverse_rotate(t_list **stack)
{
    int tmp;

    tmp = ft_lstlast(*stack)->content;
    ft_lstadd_front(stack, ft_lstnew(tmp));
    free(ft_lstlast(*stack));
    get_before_last(*stack)->next = NULL;
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}