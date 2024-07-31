/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:06:44 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/06/12 21:56:41 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//When something goes wrong, output error msg then exit.
void	ft_error(char *msg)
{
	(void)msg;
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

//Setup stack a from the args
//If there's only 1 argv, go to ft_init2(char *s)
t_node	*ft_init(int argc, char **argv)
{
	t_node	*a;
	int		idx;
	int		numb;

	idx = 1;
	a = NULL;
	if (argc < 2)
		ft_error("argc < 2\n");
	if (argc == 2)
		a = ft_init2(argv[1]);
	else
	{
		while (idx < argc)
		{
			numb = ft_atoi_strict(argv[idx]);
			ft_add_bottom(&a, ft_new_node(numb));
			idx++;
		}
	}
	return (a);
}

//Setup stack a from a string
//Which means argc == 2, the string is argv[1]
t_node	*ft_init2(char *s)
{
	t_node	*a;
	char	**temp;
	int		idx;
	int		numb;

	idx = 0;
	a = NULL;
	temp = ft_split(s, ' ');
	while (temp[idx])
	{
		numb = ft_atoi_strict(temp[idx]);
		ft_add_bottom(&a, ft_new_node(numb));
		idx++;
	}
	ft_free_strings(temp);
	return (a);
}

//strict atoi
//will output error when it's not digits or out of range
int	ft_atoi_strict(const char *str)
{
	int				sign;
	long long int	result;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error("ft_isdigit() false\n");
		result = result * 10 + (*str - '0');
		str++;
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		ft_error("out of int range\n");
	return (result);
}
