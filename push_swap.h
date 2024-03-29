/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_stack
{
	int				nbr;
	struct s_stack	*next;
}t_stack;

//instructions
//swap
void	swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//rotate
void	rotate(t_stack **lst);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//reverse rotate
void	reverse_rotate(t_stack **lst);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//init
void	ft_add_back(t_stack **lst, t_stack *new);
t_stack	*ft_newstack(int nbr);
void	ft_push(t_stack **top, int nbr);
void	init_stack(t_stack **lst, int ac, char **av);

//utils
t_stack	*ft_stacklast(t_stack *lst);
int		ft_stacksize(t_stack *lst);
int		ft_min(t_stack *lst);
int		ft_max(t_stack *lst);
int		ft_index(t_stack *lst, int nbr);
int		find_place_a(t_stack *a, int nbr);
int		find_place_b(t_stack *b, int nbr);
int		is_sorted(t_stack *lst);

//cost calculation to push b
int		case_rr_b(t_stack *a, t_stack *b, int nbr);
int		case_rrr_b(t_stack *a, t_stack *b, int nbr);
int		case_rrarb_b(t_stack *a, t_stack *b, int nbr);
int		case_rarrb_b(t_stack *a, t_stack *b, int nbr);
int		rotation_cost_b(t_stack *a, t_stack *b);

//cost calculation to push a
int		case_rr_a(t_stack *a, t_stack *b, int nbr);
int		case_rrr_a(t_stack *a, t_stack *b, int nbr);
int		case_rarrb_a(t_stack *a, t_stack *b, int nbr);
int		case_rrarb_a(t_stack *a, t_stack *b, int nbr);
int		rotation_cost_a(t_stack *a, t_stack *b);

//implement moves -> a
int		do_rr_a(t_stack **a, t_stack **b, int nbr);
int		do_rrr_a(t_stack **a, t_stack **b, int nbr);
int		do_rrarb_a(t_stack **a, t_stack **b, int nbr);
int		do_rarrb_a(t_stack **a, t_stack **b, int nbr);

//implement moves -> b
int		do_rr_b(t_stack **a, t_stack **b, int nbr);
int		do_rrr_b(t_stack **a, t_stack **b, int nbr);
int		do_rrarb_b(t_stack **a, t_stack **b, int nbr);
int		do_rarrb_b(t_stack **a, t_stack **b, int nbr);

//sort
void	sort3(t_stack **a);
void	sort_b3(t_stack **a, t_stack **b);
t_stack	*sort_b(t_stack **a);
t_stack	**sort_a(t_stack **a, t_stack **b);
void	sort(t_stack **a);

//error
void	ft_error(void);
void	ft_free(t_stack **lst);
void	ft_freestr(char **lst);
int		ft_checkdup(t_stack *lst);
int		long_atoi(char *str);

# endif