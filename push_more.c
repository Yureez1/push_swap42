/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:51 by julien            #+#    #+#             */
/*   Updated: 2024/11/19 13:36:34 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list **stack)
{
	t_list	*cu;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	cu = (*stack);
	while ((int)(__intptr_t)cu->content < (int)(__intptr_t)cu->next->content)
	{
		if (cu->next->next == NULL)
			return (1);
		cu = cu->next;
	}
	return (0);
}

void	push_next(t_list **a, t_list **b)
{
	int		half;
	t_list	*t;

	t = NULL;
	while (*b)
	{
		t = find_max(b);
		half = find_half(b, (int)(__intptr_t)t->content, (ft_lstsize(*b) / 2));
		while ((int)(__intptr_t)(*b)->content != (int)(__intptr_t)t->content)
		{
			if (half == 1)
				rotate_b(b, 0);
			else
				rrotate_b(b, 0);
		}
		push_a(a, b);
	}
}

void	ps_more(t_list **stack_a, t_list **stack_b, int *start, int *end)
{
	int len;

	len = ft_lstsize(*stack_a);
	init_index(stack_a, len);
	while (*stack_a)
	{
		if ((*stack_a)->index <= (*start))
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b, 0);
			(*start)++;
			(*end)++;
		}
		else if ((*stack_a)->index > (*start) && (*stack_a)->index < (*end))
		{
			push_b(stack_a, stack_b);
			(*start)++;
			(*end)++;
		}
		else if ((*stack_a)->index >= (*end))
			rotate_a(stack_a, 0);
	}
	push_next(stack_a, stack_b);
}