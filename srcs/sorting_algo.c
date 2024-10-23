/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:42:16 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/23 13:38:38 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// Find the min value in the chunk
int	find_min_in_chunk(t_stack **stack, int chunk_size)
{
	t_stack	*cur;
	int		min;
	int		i;

	if (!stack || !(*stack))
		return (0);
	cur = *stack;
	min = cur->value;
	i = 0;
	while (cur && i < chunk_size)
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
		i++;
	}
	return (min);
}

// Find the max value in the chunk
int	find_max_in_chunk(t_stack **stack, int chunk_size)
{
	t_stack	*cur;
	int		max;
	int		i;

	if (!stack || !(*stack))
		return (0);
	cur = *stack;
	min = cur->value;
	i = 0;
	while (cur && i < chunk_size)
	{
		if (cur->value > max)
			max = cur->value;
		cur = cur->next;
		i++;
	}
	return (max);
}

int	calculate_chunks(int stack_size, int chunk_size)
{
	int	total_chunks;

	total_chunks = stack_size / chunk_size;
	if (stack_size % chunk_size != 0)
		total_chunks++;
	return (total_chunks);
}

int	calculate_chunks_size(int stack_size)
{
	int chunk_size;
	
	if (stack_size <= 50)
		chunk_size = 5;
	else if (stack_size <= 200)
		chunk_size = 50;
	else
		chunk_size = 100;
	return (chunk_size);
}