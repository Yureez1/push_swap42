/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:45:44 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/25 19:02:16 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*first;

	if (*src)
	{
		first = *src;
		*src = (*src)->next;
		first->next = *dest;
		*dest = first;
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return;
	ft_printf("pb\n");
	push (a, b);
}

void	pa(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return;
	ft_printf("pa\n");
	push (b, a);
}
