/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:03 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/05 15:31:49 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_valid_int(char *str)
{
	long	value;
	int		i;

	i = 0;
	if (str[i] == '\0')
		errors_msg("Arguments are empty", NULL);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			errors_msg("Arguments must only contain digits", NULL);
		i++;
	}
	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		errors_msg("Argument is out of int limits", NULL);
	return (SUCCESS);
}
