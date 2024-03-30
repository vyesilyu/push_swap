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

int	do_rr_b(t_stack **a, t_stack **b, int nbr)
{
	while ((*b)->nbr != nbr && find_place_a(*a, nbr) > 0)
		rr(a, b);
	while ((*b)->nbr != nbr)
		rb(b);
	while (find_place_a(*a, nbr) > 0)
		ra(a);
	pa(a, b);
	return (-1);
}

int	do_rrr_b(t_stack **a, t_stack **b, int nbr)
{
	while ((*b)->nbr != nbr && find_place_a(*a, nbr) > 0)
		rrr(a, b);
	while ((*b)->nbr != nbr)
		rrb(b);
	while (find_place_a(*a, nbr) > 0)
		rra(a);
	pa(a, b);
	return (-1);
}

int	do_rrarb_b(t_stack **a, t_stack **b, int nbr)
{
	while (find_place_a(*a, nbr) > 0)
		rra(a);
	while ((*b)->nbr != nbr)
		rb(b);
	pa(a, b);
	return (-1);
}

int	do_rarrb_b(t_stack **a, t_stack **b, int nbr)
{
	while (find_place_a(*a, nbr) > 0)
		ra(a);
	while ((*b)->nbr != nbr)
		rrb(b);
	pa(a, b);
	return (-1);
}
