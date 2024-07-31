/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:06:36 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 21:07:23 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// return the bottom node of a stack
t_node	*ft_bottom(t_node *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

// return the stack size / how many nodes
int	ft_size(t_node *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

// return the min number in the stack
int	ft_min(t_node *s)
{
	int	i;

	i = s->nbr;
	while (s)
	{
		if (s->nbr < i)
			i = s->nbr;
		s = s->next;
	}
	return (i);
}

// return the max number in the stack
int	ft_max(t_node *s)
{
	int	i;

	i = s->nbr;
	while (s)
	{
		if (s->nbr > i)
			i = s->nbr;
		s = s->next;
	}
	return (i);
}

// create a stack node from a integer
t_node	*ft_new_node(int i)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		ft_putstr_fd("Error in ft_new_node().\n", 1);
	node->nbr = i;
	node->next = NULL;
	return (node);
}
