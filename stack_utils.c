/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_place_b(t_stack *b, int nbr)
{
	t_stack	*temp;
	int		i;

	i = 1;
	if (nbr > b->nbr && nbr < ft_stacklast(b)->nbr)
		i = 0;
	else if (nbr > ft_max(b) || nbr < ft_min(b))
		i = ft_index(b, ft_max(b));
	else
	{
		temp = b->next;
		while (b->nbr < nbr || temp->nbr > nbr)
		{
			b = b->next;
			temp = b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_stack *a, int nbr)
{
	t_stack	*temp;
	int		i;

	i = 1;
	if (nbr < a->nbr && nbr > ft_stacklast(a)->nbr)
		i = 0;
	else if (nbr > ft_max(a) || nbr < ft_min(a))
		i = ft_index(a, ft_min(a));
	else
	{
		temp = a->next;
		while (a->nbr > nbr || temp->nbr < nbr)
		{
			a = a->next;
			temp = a->next;
			i++;
		}
	}
	return (i);
}
