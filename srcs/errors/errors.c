/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:32:29 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/24 19:57:55 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	errors_msg(char *message, int *numbers)
{
	if (numbers)
		free(numbers);
	ft_printf(RED "ERROR\n" GREY "%s\n" RESET, message);
	exit(EXIT_FAILURE);
}

