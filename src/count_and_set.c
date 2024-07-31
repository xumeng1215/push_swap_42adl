/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:22:29 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 20:57:52 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// called before actually push node from stack a to stack b
// will find out the operation needed for each node in stack a
// if push it to stack b while keep b in order
// then return the minimum number, so the best case is set
int	set_case_atob(t_node *a, t_node *b)
{
	int		min;
	t_node	*temp;

	min = ft_size(a) + ft_size(b);
	temp = a;
	while (temp)
	{
		if (min > count_rr_atob(a, b, temp->nbr))
			min = count_rr_atob(a, b, temp->nbr);
		if (min > count_rrr_atob(a, b, temp->nbr))
			min = count_rrr_atob(a, b, temp->nbr);
		if (min > count_rrarb_atob(a, b, temp->nbr))
			min = count_rrarb_atob(a, b, temp->nbr);
		if (min > count_rrbra_atob(a, b, temp->nbr))
			min = count_rrbra_atob(a, b, temp->nbr);
		temp = temp->next;
	}
	return (min);
}

// find out how many operation needed if using rr operation first
// and then use ra or rb operation if necessary
// to push the node(which ->nbr == n) from stack a to stack b (operation pb)
int	count_rr_atob(t_node *a, t_node *b, int n)
{
	int	count;

	count = ft_index(a, n);
	if (count < find_place_in_b(b, n))
		count = find_place_in_b(b, n);
	return (count);
}

int	count_rrr_atob(t_node *a, t_node *b, int n)
{
	int	count;

	count = 0;
	if (ft_index(a, n))
		count = ft_size(a) - ft_index(a, n);
	if (find_place_in_b(b, n))
	{
		if (count < ft_size(b) - find_place_in_b(b, n))
			count = ft_size(b) - find_place_in_b(b, n);
	}
	return (count);
}

int	count_rrarb_atob(t_node *a, t_node *b, int n)
{
	int	count;

	count = find_place_in_b(b, n);
	if (ft_index(a, n))
		count = count + (ft_size(a) - ft_index(a, n));
	return (count);
}

int	count_rrbra_atob(t_node *a, t_node *b, int n)
{
	int	count;

	count = ft_index(a, n);
	if (find_place_in_b(b, n))
		count = count + (ft_size(b) - find_place_in_b(b, n));
	return (count);
}
