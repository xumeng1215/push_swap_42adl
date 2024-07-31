/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:57:36 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:55:52 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Sort stack a when it has 3 nodes
// only 6 possible cases
/*
1 1 2 2 3 3
2 3 1 3 2 1
3 2 3 1 1 2
*/
void	ft_sort_3(t_node **a)
{
	int	max;

	max = ft_max(*a);
	if (max == (*a)->nbr)
		ra(a, 1);
	else if (max == (*a)->next->nbr)
		rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}

// push node from stack a to stack b
// while keep the stack b in order
// until 3 nodes left in a
void	push_and_sort_b(t_node **a, t_node **b)
{
	if (ft_size(*a) > 3 && !ft_is_sorted(*a))
		pb(b, a, 1);
	if (ft_size(*a) > 3 && !ft_is_sorted(*a))
		pb(b, a, 1);
	if (ft_size(*a) > 3 && !ft_is_sorted(*a))
		pb_until_3_left(b, a);
}

void	pb_until_3_left(t_node **b, t_node **a)
{
	int		i;
	t_node	*temp;

	while (ft_size(*a) > 3 && !ft_is_sorted(*a))
	{
		temp = *a;
		i = set_case_atob(*a, *b);
		while (i >= 0)
		{
			if (i == count_rr_atob(*a, *b, temp->nbr))
				i = do_rr_atob(a, b, temp->nbr);
			else if (i == count_rrr_atob(*a, *b, temp->nbr))
				i = do_rrr_atob(a, b, temp->nbr);
			else if (i == count_rrarb_atob(*a, *b, temp->nbr))
				i = do_rrarb_atob(a, b, temp->nbr);
			else if (i == count_rrbra_atob(*a, *b, temp->nbr))
				i = do_rrbra_atob(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
}

// push all node from stack b to stack a
void	push_and_sort_a(t_node **a, t_node **b)
{
	int		i;
	t_node	*temp;

	while (*b)
	{
		temp = *b;
		i = set_case_btoa(*a, *b);
		while (i >= 0)
		{
			if (i == count_rr_btoa(*a, *b, temp->nbr))
				i = do_rr_btoa(a, b, temp->nbr);
			else if (i == count_rrr_btoa(*a, *b, temp->nbr))
				i = do_rrr_btoa(a, b, temp->nbr);
			else if (i == count_rbrra_btoa(*a, *b, temp->nbr))
				i = do_rrarb_btoa(a, b, temp->nbr);
			else if (i == count_rrbra_btoa(*a, *b, temp->nbr))
				i = do_rrbra_btoa(a, b, temp->nbr);
			else
				temp = temp->next;
		}
	}
}

// rotate stack a to put the ft_min(a) on top
void	find_min_and_rotate(t_node *a)
{
	int	i;

	i = ft_index(a, ft_min(a));
	if (i < ft_size(a) - i)
	{
		while (a->nbr != ft_min(a))
			ra(&a, 1);
	}
	else
	{
		while (a->nbr != ft_min(a))
			rra(&a, 1);
	}
}
