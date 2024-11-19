/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:57:28 by julien            #+#    #+#             */
/*   Updated: 2024/11/18 17:28:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reverse_rot(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_list **a)
{
	reverse_rot(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	reverse_rot(b);
	ft_printf("rrb\n");
}
