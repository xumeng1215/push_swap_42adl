/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_set_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:22:29 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 20:57:52 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	set_case_btoa(t_node *a, t_node *b)
{
	int		min;
	t_node	*temp;

	temp = b;
	min = ft_size(a) + ft_size(b);
	while (temp)
	{
		if (min > count_rr_btoa(a, b, temp->nbr))
			min = count_rr_btoa(a, b, temp->nbr);
		if (min > count_rrr_btoa(a, b, temp->nbr))
			min = count_rrr_btoa(a, b, temp->nbr);
		if (min > count_rbrra_btoa(a, b, temp->nbr))
			min = count_rbrra_btoa(a, b, temp->nbr);
		if (min > count_rrbra_btoa(a, b, temp->nbr))
			min = count_rrbra_btoa(a, b, temp->nbr);
		temp = temp->next;
	}
	return (min);
}

int	count_rr_btoa(t_node *a, t_node *b, int n)
{
	int	count;

	count = ft_index(b, n);
	if (count < find_place_in_a(a, n))
		count = find_place_in_a(a, n);
	return (count);
}

int	count_rrr_btoa(t_node *a, t_node *b, int n)
{
	int	count;

	count = 0;
	if (ft_index(b, n))
		count = ft_size(b) - ft_index(b, n);
	if (find_place_in_a(a, n))
	{
		if (count < ft_size(a) - find_place_in_a(a, n))
			count = ft_size(a) - find_place_in_a(a, n);
	}
	return (count);
}

int	count_rrbra_btoa(t_node *a, t_node *b, int n)
{
	int	count;

	count = find_place_in_a(a, n);
	if (ft_index(b, n))
		count += ft_size(b) - ft_index(b, n);
	return (count);
}

int	count_rbrra_btoa(t_node *a, t_node *b, int n)
{
	int	count;

	count = ft_index(b, n);
	if (find_place_in_a(a, n))
		count = ft_size(a) - find_place_in_a(a, n);
	return (count);
}
