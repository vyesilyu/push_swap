/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
}

void	ft_freestr(char **lst)
{
	char	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		lst++;
		free(temp);
	}
	*lst = NULL;
}

int	ft_checkdup(t_stack *lst)
{
	t_stack	*temp;

	while (lst)
	{
		temp = lst->next;
		while (temp)
		{
			if (lst->nbr == temp->nbr)
				return (1);
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	long_atoi(char *str)
{
	long long int	i;
	int				sign;

	i = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		ft_error();
	return (sign * i);
}
