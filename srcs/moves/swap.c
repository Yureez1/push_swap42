/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:45:51 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/24 19:57:49 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = NULL;
	second = NULL;
	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
	}
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_stack **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
