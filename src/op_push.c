/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:12:13 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:53:28 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// General push operation
static void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = temp;
}

// push top node from b to a
void	pa(t_node **a, t_node **b, int i)
{
	push(a, b);
	if (i == 1)
		ft_printf("pa\n");
}

// push top node from a to b
void	pb(t_node **b, t_node **a, int i)
{
	push(b, a);
	if (i == 1)
		ft_printf("pb\n");
}
