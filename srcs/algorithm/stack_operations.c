/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:42:16 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/25 18:47:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_chunks_to_b(t_stack **a, t_stack **b, int stack_size)
{
	int chunk_size;
	int total_chunks;
	int i;
	
	chunk_size = calculate_chunks_size(stack_size);
	total_chunks = calculate_chunks(stack_size, chunk_size);
	i = 0;
	while (i < total_chunks)
	{
		push_min_max_to_b(a, b, chunk_size);
	}
}

void push_min_max_to_b(t_stack **a, t_stack **b, int chunk_size)
{
	int i;
	int min;
	int max;

	i = 0;
	min = find_min_in_chunk(a, chunk_size);
	max = find_max_in_chunk(a, chunk_size);
	while(i < chunk_size && *a)
	{
		if ((*a)->value == min || (*a)->value == max)
		{
			pb(a, b);
			if ((*b)->value == max)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}

void	sort_and_push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack *temp;
	
	if(!stack || !(*stack))
		return;
	while(*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
