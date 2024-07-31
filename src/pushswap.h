/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:50:52 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 22:54:19 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <printf.h>
# include <time.h>
# include <stdarg.h>

// stack node struct
typedef struct s_stack_node
{
	int					nbr;
	struct s_stack_node	*next;
}	t_node;

// void print_stack(t_node *stack);
// void logging(const char *format, ...);

// operations
void	pa(t_node **a, t_node **b, int i);
void	pb(t_node **b, t_node **a, int i);
void	sa(t_node **a, int i);
void	sb(t_node **b, int i);
void	ss(t_node **a, t_node **b, int i);
void	ra(t_node **a, int i);
void	rb(t_node **b, int i);
void	rr(t_node **a, t_node **b, int i);
void	rra(t_node **a, int i);
void	rrb(t_node **b, int i);
void	rrr(t_node **a, t_node **b, int i);

// sort
void	ft_sort_3(t_node **a);
void	ft_sort_stack(t_node **a);
void	push_and_sort_b(t_node **b, t_node **a);
void	pb_until_3_left(t_node **b, t_node **a);
void	push_and_sort_a(t_node **a, t_node **b);
void	find_min_and_rotate(t_node *a);

// args
t_node	*ft_init(int argc, char **argv);
t_node	*ft_init2(char *s);
int		ft_atoi_strict(const char *str);

// stack_utils
t_node	*ft_bottom(t_node *s);
t_node	*ft_new_node(int i);
int		ft_size(t_node *s);
int		ft_min(t_node *s);
int		ft_max(t_node *s);
void	ft_add_bottom(t_node **stack, t_node *node);
void	ft_free_stack(t_node **stack);
int		ft_is_sorted(t_node *s);
int		ft_no_dup(t_node *s);
int		ft_index(t_node *s, int nbr);
int		find_place_in_b(t_node *b, int nbr);
int		find_place_in_a(t_node *a, int nbr);

// set the best cases
int		set_case_atob(t_node *a, t_node *b);
int		set_case_btoa(t_node *a, t_node *b);

// count operations when push from a to b
int		count_rr_atob(t_node *a, t_node *b, int n);
int		count_rrr_atob(t_node *a, t_node *b, int n);
int		count_rrarb_atob(t_node *a, t_node *b, int n);
int		count_rrbra_atob(t_node *a, t_node *b, int n);

// count operations when push from b to a
int		count_rr_btoa(t_node *a, t_node *b, int n);
int		count_rrr_btoa(t_node *a, t_node *b, int n);
int		count_rrbra_btoa(t_node *a, t_node *b, int n);
int		count_rbrra_btoa(t_node *a, t_node *b, int n);

// perform the operation
int		do_rr_atob(t_node **a, t_node **b, int n);
int		do_rrr_atob(t_node **a, t_node **b, int n);
int		do_rrarb_atob(t_node **a, t_node **b, int n);
int		do_rrbra_atob(t_node **a, t_node **b, int n);

int		do_rr_btoa(t_node **a, t_node **b, int n);
int		do_rrr_btoa(t_node **a, t_node **b, int n);
int		do_rrarb_btoa(t_node **a, t_node **b, int n);
int		do_rrbra_btoa(t_node **a, t_node **b, int n);

// output error
void	ft_error(char *msg);

#endif // pushswap.h
