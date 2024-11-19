/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:54 by julien            #+#    #+#             */
/*   Updated: 2024/11/18 17:28:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_integer(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX))
			return (0);
		if ((sign == -1 && res > INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

void	check_parameter(char *str, t_list **stack_a, char **tab)
{
	if (!is_integer(str))
		error_msg("Invalid parameter.", stack_a, tab);
	init_list(str, stack_a, tab);
}
