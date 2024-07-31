/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:10:52 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/13 23:24:59 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// find the correct place of a number in stack b
// stack b is in descending order
int	find_place_in_b(t_node *b, int nbr)
{
	int		i;
	t_node	*temp;

	i = 1;
	if ((nbr > b->nbr) && (nbr < ft_bottom(b)->nbr))
		i = 0;
	else if (nbr > ft_max(b) || nbr < ft_min(b))
		i = ft_index(b, ft_max(b));
	else
	{
		temp = b->next;
		while (!(nbr < b->nbr && nbr > temp->nbr))
		{
			b = b->next;
			temp = b->next;
			i++;
		}
	}
	return (i);
}

// find the correct place of a number in stack a
// stack a is in ascending order
int	find_place_in_a(t_node *a, int nbr)
{
	int		i;
	t_node	*temp;

	i = 1;
	if ((nbr < a->nbr) && (nbr > ft_bottom(a)->nbr))
		i = 0;
	else if (nbr < ft_min(a) || nbr > ft_max(a))
		i = ft_index(a, ft_min(a));
	else
	{
		temp = a->next;
		while (!(nbr > a->nbr && nbr < temp->nbr))
		{
			a = a->next;
			temp = a->next;
			i++;
		}
	}
	return (i);
}
