/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rr_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = find_place_a(a, nbr);
	if (i < ft_index(b, nbr))
		i = ft_index(b, nbr);
	return (i);
}

int	case_rrr_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (find_place_a(a, nbr))
		i = ft_stacksize(a) - find_place_a(a, nbr);
	if ((i < ft_stacksize(b) - ft_index(b, nbr)) && ft_index(b, nbr))
		i = ft_stacksize(b) - ft_index(b, nbr);
	return (i);
}

int	case_rarrb_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_index(b, nbr))
		i = ft_stacksize(b) - ft_index(b, nbr);
	i = find_place_a(a, nbr) + i;
	return (i);
}

int	case_rrarb_a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (find_place_a(a, nbr))
		i = ft_stacksize(a) - find_place_a(a, nbr);
	i = ft_index(b, nbr) + i;
	return (i);
}

int	rotation_cost_a(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = b;
	i = case_rrr_a(a, b, b->nbr);
	while (temp)
	{
		if (i > case_rr_a(a, b, temp->nbr))
			i = case_rr_a(a, b, temp->nbr);
		if (i > case_rrr_a(a, b, temp->nbr))
			i = case_rrr_a(a, b, temp->nbr);
		if (i > case_rarrb_a(a, b, temp->nbr))
			i = case_rarrb_a(a, b, temp->nbr);
		if (i > case_rrarb_a(a, b, temp->nbr))
			i = case_rrarb_a(a, b, temp->nbr);
		temp = temp->next;
	}
	return (i);
}
