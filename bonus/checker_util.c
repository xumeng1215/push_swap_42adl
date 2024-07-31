/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:52:06 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/13 22:36:28 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_equal(char *s, char *t)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0' && t[i] != '\0')
	{
		if (s[i] != t[i])
			return (0);
		i++;
	}
	if (s[i] == '\n' && t[i] == '\0')
		return (1);
	return (0);
}

char	*ft_checker_do_op(t_node **a, t_node **b, char *op)
{
	if (ft_is_equal(op, "sa"))
		sa(a, 0);
	else if (ft_is_equal(op, "sb"))
		sb(b, 0);
	else if (ft_is_equal(op, "ss"))
		ss(a, b, 0);
	else if (ft_is_equal(op, "pa"))
		pa(a, b, 0);
	else if (ft_is_equal(op, "pb"))
		pb(b, a, 0);
	else if (ft_is_equal(op, "ra"))
		ra(a, 0);
	else if (ft_is_equal(op, "rb"))
		rb(b, 0);
	else if (ft_is_equal(op, "rr"))
		rr(a, b, 0);
	else if (ft_is_equal(op, "rra"))
		rra(a, 0);
	else if (ft_is_equal(op, "rrb"))
		rrb(b, 0);
	else if (ft_is_equal(op, "rrr"))
		rrr(a, b, 0);
	else
		ft_error("Error when checker do op\n");
	return (get_next_line(0));
}

void	ft_check_op(t_node **a, t_node **b, char *op)
{
	char	*temp;

	while (op && *op != '\n')
	{
		temp = op;
		op = ft_checker_do_op(a, b, op);
		free(temp);
	}
	if (*b == NULL && ft_is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(op);
}
