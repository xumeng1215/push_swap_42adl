/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:05:41 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:53:13 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// General rotate operation
// Shift one node up
// The first node will become the last one
static void	rotate(t_node **s)
{
	t_node	*temp;

	if (!*s || !(*s)->next)
		return ;
	temp = *s;
	*s = ft_bottom(*s);
	(*s)->next = temp;
	*s = temp->next;
	temp->next = NULL;
}

// rotate a. shift 1 node up in stack a
void	ra(t_node **a, int i)
{
	rotate(a);
	if (i == 1)
		ft_printf("ra\n");
}

// rotate b. shift 1 node up in stack b
void	rb(t_node **b, int i)
{
	rotate(b);
	if (i == 1)
		ft_printf("rb\n");
}

// rotate a and b. shift 1 node up in stack a and b
void	rr(t_node **a, t_node **b, int i)
{
	rotate(a);
	rotate(b);
	if (i == 1)
		ft_printf("rr\n");
}
