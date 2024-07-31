/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:45:59 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/13 22:44:53 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void print_stack(t_node *stack)
// {
// 	t_node *current = stack;

// 	while (current != NULL)
// 	{
// 		printf("%d | ", current->nbr);
// 		current = current->next;
// 	}
// 	printf("\n");
// }

// Main / Start
int	main(int argc, char **argv)
{
	t_node	*a;

	a = ft_init(argc, argv);
	if (!a || !ft_no_dup(a))
	{
		ft_free_stack(&a);
		ft_error("Error in main function.\n");
	}
	if (!ft_is_sorted(a))
		ft_sort_stack(&a);
	ft_free_stack(&a);
	return (0);
}

// Main sort function
void	ft_sort_stack(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (ft_size(*a) == 2)
		sa(a, 1);
	else if (ft_size(*a) == 3)
		ft_sort_3(a);
	else
	{
		push_and_sort_b(a, &b);
		if (!ft_is_sorted(*a))
			ft_sort_3(a);
		push_and_sort_a(a, &b);
		find_min_and_rotate(*a);
	}
}
