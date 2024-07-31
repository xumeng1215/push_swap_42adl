/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:46:31 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:55:21 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	do_rr_btoa(t_node **a, t_node **b, int n)
{
	while ((*b)->nbr != n && find_place_in_a(*a, n) > 0)
		rr(a, b, 1);
	while ((*b)->nbr != n)
		rb(b, 1);
	while (find_place_in_a(*a, n) > 0)
		ra(a, 1);
	pa(a, b, 1);
	return (-5);
}

int	do_rrr_btoa(t_node **a, t_node **b, int n)
{
	while ((*b)->nbr != n && find_place_in_a(*a, n) > 0)
		rrr(a, b, 1);
	while ((*b)->nbr != n)
		rrb(b, 1);
	while (find_place_in_a(*a, n) > 0)
		rra(a, 1);
	pa(a, b, 1);
	return (-6);
}

int	do_rrarb_btoa(t_node **a, t_node **b, int n)
{
	while ((*b)->nbr != n)
		rb(b, 1);
	while (find_place_in_a(*a, n) > 0)
		rra(a, 1);
	pa(a, b, 1);
	return (-7);
}

int	do_rrbra_btoa(t_node **a, t_node **b, int n)
{
	while (find_place_in_a(*a, n) > 0)
		ra(a, 1);
	while ((*b)->nbr != n)
		rrb(b, 1);
	pa(a, b, 1);
	return (-8);
}
