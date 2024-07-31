/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:52:41 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/13 22:33:01 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../src/pushswap.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_is_equal(char *s, char *t);
char	*ft_checker_do_op(t_node **a, t_node **b, char *op);
void	ft_check_op(t_node **a, t_node **b, char *op);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_alloc_extra(char *str, int nb);
char	*ft_copy_str(char *str);
char	*ft_trim(char *str);
char	*ft_strcat(char *dest, char *src);
int		ft_find_line(char *str);
char	*ft_read_line(int fd, char *str);
char	*get_next_line(int fd);

#endif