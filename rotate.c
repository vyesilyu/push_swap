/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	*lst = ft_stacklast(*lst);
	(*lst)->next = temp;
	*lst = temp->next;
	temp->next = NULL;
}

void	ra(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
