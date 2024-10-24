/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:45:47 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/24 19:57:33 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack && (*stack)->next)
	{
		second_last = *stack;
		while (second_last->next->next != NULL)
		{
			second_last = second_last->next;
		}
		last = second_last->next;
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}

void	ra(t_stack **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rb(t_stack **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}
