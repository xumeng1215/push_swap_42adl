/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:31:42 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:51:58 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// General swap operation
static void	swap(t_node **s)
{
	t_node	*temp;

	if (!*s || !(*s)->next)
		return ;
	temp = *s;
	*s = (*s)->next;
	temp->next = (*s)->next;
	(*s)->next = temp;
}

// swap top 2 node of stack a
void	sa(t_node **a, int i)
{
	swap(a);
	if (i == 1)
		ft_printf("sa\n");
}

// swap top 2 node of stack b
void	sb(t_node **b, int i)
{
	swap(b);
	if (i == 1)
		ft_printf("sb\n");
}

// swap top 2 node of stack a and b
void	ss(t_node **a, t_node **b, int i)
{
	swap(a);
	swap(b);
	if (i == 1)
		ft_printf("ss\n");
}
