/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:32:29 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/21 15:43:42 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	errors_msg(char *message)
{
	ft_printf(RED "ERROR\n" GREY "%s\n" RESET, message);
	return (ERROR);
}

void	display_error(void)
{
}
