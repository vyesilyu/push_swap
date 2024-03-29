/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
}

void	sa(t_stack **a)
{
	if (!*a || !((*a)->next))
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (!*b || !((*b)->next))
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if ((!*a || !((*a)->next)) || (!*b || !((*b)->next)))
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
