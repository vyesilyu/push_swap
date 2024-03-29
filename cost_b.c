/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rr_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = find_place_b(b, nbr);
	if (i < ft_index(a, nbr))
		i = ft_index(a, nbr);
	return (i);
}

int	case_rrr_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (find_place_b(b, nbr))
		i = ft_stacksize(b) - find_place_b(b, nbr);
	if ((i < ft_stacksize(a) - ft_index(a, nbr)) && ft_index(a, nbr))
		i = ft_stacksize(a) - ft_index(a, nbr);
	return (i);
}

int	case_rarrb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (find_place_b(b, nbr))
		i = ft_stacksize(b) - find_place_b(b, nbr);
	i = ft_index(a, nbr) + i;
	return (i);
}

int	case_rrarb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_index(a, nbr))
		i = ft_stacksize(a) - ft_index(a, nbr);
	i = find_place_b(b, nbr) + i;
	return (i);
}

int	rotation_cost_b(t_stack *a, t_stack *b)
{
	int			i;
	t_stack *temp;

	temp = a;
	i = case_rrr_b(a, b, a->nbr);
	while (temp)
	{
		if (i > case_rr_b(a, b, temp->nbr))
			i = case_rr_b(a, b, temp->nbr);
		if (i > case_rrr_b(a, b, temp->nbr))
			i = case_rrr_b(a, b, temp->nbr);
		if (i > case_rarrb_b(a, b, temp->nbr))
			i = case_rarrb_b(a, b, temp->nbr);
		if (i > case_rrarb_b(a, b, temp->nbr))
			i = case_rrarb_b(a, b, temp->nbr);
		temp = temp->next;
	}
	return (i);
}
