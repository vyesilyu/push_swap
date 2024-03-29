/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		rra(a);
		sa(a);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ra(a);
		if (!is_sorted(*a))
			sa(a);
	}
	else
	{
		if (ft_index(*a, ft_max(*a)) == 1)
			rra(a);
		else
			sa(a);
	}
}

void	sort_b3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	while (ft_stacksize(*a) > 3 && !is_sorted(*a))
	{
		temp = *a;
		i = rotation_cost_b(*a, *b);
		while (i >= 0)
		{
			if (i == case_rr_b(*a, *b, temp->nbr))
				i = do_rr_a(a, b, temp->nbr);
			else if (i == case_rrr_b(*a, *b, temp->nbr))
				i = do_rrr_a(a, b, temp->nbr);
			else if (i == case_rrarb_b(*a, *b, temp->nbr))
				i = do_rrarb_a(a, b, temp->nbr);
			else if (i == case_rarrb_b(*a, *b, temp->nbr))
				i = do_rarrb_a(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
}

t_stack	*sort_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_stacksize(*a) > 3 && !is_sorted(*a))
		pb(a, &b);
	if (ft_stacksize(*a) > 3 && !is_sorted(*a))
		pb(a, &b);
	if (ft_stacksize(*a) > 3 && !is_sorted(*a))
		sort_b3(a, &b);
	if (!is_sorted(*a))
		sort3(a);
	return (b);
}

t_stack	**sort_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	while (*b)
	{
		temp = *b;
		i = rotation_cost_a(*a, *b);
		while (i >= 0)
		{
			if (i == case_rr_a(*a, *b, temp->nbr))
				i = do_rr_b(a, b, temp->nbr);
			else if (i == case_rrr_a(*a, *b, temp->nbr))
				i = do_rrr_b(a, b, temp->nbr);
			else if (i == case_rrarb_a(*a, *b, temp->nbr))
				i = do_rrarb_b(a, b, temp->nbr);
			else if (i == case_rarrb_a(*a, *b, temp->nbr))
				i = do_rarrb_b(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
	return (a);
}

void	sort(t_stack **a)
{
	t_stack	*b;
	int		i;

	b = NULL;
	if (ft_stacksize(*a) == 2)
		sa(a);
	else
	{
		b = sort_b(a);
		a = sort_a(a, &b);
		i = ft_index(*a, ft_min(*a));
		if (i < ft_stacksize(*a) - i)
		{
			while ((*a)->nbr != ft_min(*a))
				ra(a);
		}
		else
		{
			while ((*a)->nbr != ft_min(*a))
				rra(a);
		}
	}
}
