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
    if(stack_src == NULL)
        return ;
    ft_lstadd_front(stack_dest, ft_lstnew((*stack_src)->content));
    clear_first_element(stack_src);
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
    t_list *tmp2;

    tmp = ft_lstlast(*stack)->content;
    ft_lstadd_front(stack, ft_lstnew(tmp));
    tmp2 = ft_lstlast(*stack);
    get_before_last(*stack)->next = NULL;
    free(tmp2);
}