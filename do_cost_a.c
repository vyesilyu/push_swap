/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rr_a(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->nbr != nbr && find_place_b(*b, nbr) > 0)
		rr(a, b);
	while ((*a)->nbr != nbr)
		ra(a);
	while (find_place_b(*b, nbr) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

int	do_rrr_a(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->nbr != nbr && find_place_b(*b, nbr) > 0)
		rrr(a, b);
	while ((*a)->nbr != nbr)
		rra(a);
	while (find_place_b(*b, nbr) > 0)
		rrb(b);
	pb(a, b);
	return (-1);
}

int	do_rrarb_a(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->nbr != nbr)
		rra(a);
	while (find_place_b(*b, nbr) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

int	do_rarrb_a(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->nbr != nbr)
		ra(a);
	while (find_place_b(*b, nbr) > 0)
		rrb(b);
	pb(a, b);
	return (-1);
}

