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

int	ft_min(t_stack *lst)
{
	int	min;

	min = lst->nbr;
	while (lst)
	{
		if (lst->nbr < min)
			min = lst->nbr;
		lst = lst->next;
	}
	return (min);
}

int	ft_max(t_stack *lst)
{
	int	max;

	max = lst->nbr;
	while (lst)
	{
		if (lst->nbr > max)
			max = lst->nbr;
		lst = lst->next;
	}
	return (max);
}

int	ft_index(t_stack *lst, int nbr)
{
	int	i;

	i = 0;
	while (lst->nbr != nbr)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	is_sorted(t_stack *lst)
{
	int	i;

	i = lst->nbr;
	while (lst)
	{
		if (i > lst->nbr)
			return (0);
		i = lst->nbr;
		lst = lst->next;
	}
	return (1);
}
