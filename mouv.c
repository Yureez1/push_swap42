/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:26:28 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/17 18:24:20 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack && (*stack)->next)
	{
		a = *stack;
		b = (*stack)->next;
	}
	a->next = b->next;
	b->next = a;
	*stack = b;
}

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

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
}

void	reverse(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
}