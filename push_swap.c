/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	a = NULL;
	if (ac > 1)
	{
		init_stack(&a, ac, av);
		if (!a || ft_checkdup(a))
		{
			ft_free(&a);
			ft_error();
		}
		if (!is_sorted(a))
			sort(&a);
		ft_free(&a);
	}
	return (0);
}
