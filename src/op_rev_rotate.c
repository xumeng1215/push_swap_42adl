/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:31:48 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:53:20 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// General reverse rotate operation
// The while loop will set temp to the last node
// and prev will be set to the second last node
static void	rev_rotate(t_node **s)
{
	t_node	*prev;
	t_node	*temp;

	if (!*s || !(*s)->next)
		return ;
	temp = *s;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	temp->next = *s;
	*s = temp;
	prev->next = NULL;
}

// reverse rotate a. shift 1 node down in stack a
void	rra(t_node **a, int i)
{
	rev_rotate(a);
	if (i == 1)
		ft_printf("rra\n");
}

// reverse rotate b. shift 1 node down in stack b
void	rrb(t_node **b, int i)
{
	rev_rotate(b);
	if (i == 1)
		ft_printf("rrb\n");
}

// reverse rotate a and b. shift 1 node down in stack a and b
void	rrr(t_node **a, t_node **b, int i)
{
	rev_rotate(a);
	rev_rotate(b);
	if (i == 1)
		ft_printf("rrr\n");
}
