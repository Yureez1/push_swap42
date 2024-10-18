/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:26:28 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/18 18:58:13 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
	}
	first->next = second->next;
	second->next = first;
	*stack = second;
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
	t_stack	*temp;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		*stack = (*stack)->next;
		temp = *stack;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = first;
		first->next = NULL;
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack && (*stack)->next)
	{
		second_last = *stack;
		while (second_last->second_last->next != NULL)
		{
			second_last = second_last->next;
		}
		last = second_last->next;
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
