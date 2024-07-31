/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:04:55 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/13 22:44:42 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// find the index of a number in the stack
// top node index is 0
int	ft_index(t_node *s, int nbr)
{
	int	i;

	i = 0;
	while (s->nbr != nbr)
	{
		i++;
		s = s->next;
	}
	return (i);
}

// insert a node to the bottom of stack
// used when initialize the stack a
void	ft_add_bottom(t_node **stack, t_node *node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = node;
	else
		(ft_bottom(*stack))->next = node;
}

// free a stack
void	ft_free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

// check if a stack is sorted
int	ft_is_sorted(t_node *s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->nbr > s->next->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}

// Check if there's no duplication value in stack a
// return 1 if there's no duplication, which means ok to go
int	ft_no_dup(t_node *s)
{
	t_node	*next_node;

	if (!s)
		return (1);
	while (s)
	{
		next_node = s->next;
		while (next_node)
		{
			if (s->nbr == next_node->nbr)
				return (0);
			next_node = next_node->next;
		}
		s = s->next;
	}
	return (1);
}
