/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:32:29 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/22 17:00:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	errors_msg(char *message, int *numbers)
{
	if (numbers)
		free(numbers);
	ft_printf(RED "ERROR\n" GREY "%s\n" RESET, message);
	exit(EXIT_FAILURE);
}

void	display_error(void)
{
}
