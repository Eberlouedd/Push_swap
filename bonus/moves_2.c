/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:52:04 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/26 19:15:04 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!is_empty(*stack_a))
		rotate(stack_a);
	if (!is_empty(*stack_b))
		rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!is_empty(*stack_a))
		reverse_rotate(stack_a);
	if (!is_empty(*stack_b))
		reverse_rotate(stack_b);
}

t_list	*get_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
