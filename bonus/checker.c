/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:46:47 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 23:52:38 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*op;

	b = NULL;
	a = ft_init(argc, argv);
	if (!a || !ft_no_dup(a))
	{
		ft_free_stack(&a);
		ft_error("Error in checker main\n");
	}
	op = get_next_line(0);
	if (!op)
	{
		if (!ft_is_sorted(a))
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
	}
	else
		ft_check_op(&a, &b, op);
	ft_free_stack(&b);
	ft_free_stack(&a);
	return (0);
}
