/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:46:31 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:54:53 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// do rr first
// if n still not on top of a, do ra
// if the correct place in b is still not on top, do rb
// then do pb
// return -1 mark the end of operation
int	do_rr_atob(t_node **a, t_node **b, int n)
{
	while ((*a)->nbr != n && find_place_in_b(*b, n) > 0)
		rr(a, b, 1);
	while ((*a)->nbr != n)
		ra(a, 1);
	while (find_place_in_b(*b, n) > 0)
		rb(b, 1);
	pb(b, a, 1);
	return (-1);
}

// do rrr first
// if n still not on top of a, do rra
// if the correct place in b is still not on top, do rrb
// then do pb
// return -1 mark the end of operation
int	do_rrr_atob(t_node **a, t_node **b, int n)
{
	while ((*a)->nbr != n && find_place_in_b(*b, n) > 0)
		rrr(a, b, 1);
	while ((*a)->nbr != n)
		rra(a, 1);
	while (find_place_in_b(*b, n) > 0)
		rrb(b, 1);
	pb(b, a, 1);
	return (-2);
}

// do rra first until n is on top of a
// then do rb until the correct place in b is on top
// then do pb
// return -1 mark the end of operation
int	do_rrarb_atob(t_node **a, t_node **b, int n)
{
	while ((*a)->nbr != n)
		rra(a, 1);
	while (find_place_in_b(*b, n) > 0)
		rb(b, 1);
	pb(b, a, 1);
	return (-3);
}

// do rrb first until the correct place in b is on top
// then do ra until n is on top of a
// then do pb
// return -1 mark the end of operation
int	do_rrbra_atob(t_node **a, t_node **b, int n)
{
	while (find_place_in_b(*b, n) > 0)
		rrb(b, 1);
	while ((*a)->nbr != n)
		ra(a, 1);
	pb(b, a, 1);
	return (-4);
}
