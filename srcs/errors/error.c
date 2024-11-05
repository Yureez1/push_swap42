/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:50 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/05 15:31:46 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	error_msg(t_stack **a, t_stack **b, char **argv, int string)
{
	write(2, "Error\n", 6);
	free_all(a, b, argv, string);
	exit(1);
}
