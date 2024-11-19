/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:05 by julien            #+#    #+#             */
/*   Updated: 2024/11/19 13:36:48 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_zero(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
}

void	init_index(t_list **stack_a, int len)
{
	t_list	*temp;
	t_list	*current;
	int		min;
	int		i;

	index_zero(stack_a);
	i = 1;
	while (len > 0)
	{
		min = INT32_MAX;
		current = *stack_a;
		while (current)
		{
			if ((int)(__intptr_t)current->content < min && current->index == 0)
			{
				min = (int)(__intptr_t)current->content;
				temp = current;
			}
			current = current->next;
		}
		temp->index = i;
		i++;
		len--;
	}
}

t_list	*find_min(t_list **stack)
{
	t_list	*temp;
	t_list	*min_node;
	int		min;

	min = INT32_MAX;
	temp = *stack;
	min_node = NULL;
	while (temp)
	{
		if ((int)(__intptr_t)temp->content < min)
		{
			min = (int)(__intptr_t)temp->content;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

t_list	*find_max(t_list **stack)
{
	t_list	*temp;
	t_list	*max_node;
	int		max;

	max = INT32_MIN;
	temp = *stack;
	max_node = NULL;
	while (temp)
	{
		if ((int)(__intptr_t)temp->content > max)
		{
			max = (int)(__intptr_t)temp->content;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

int	find_half(t_list **stack, int max, int len)
{
	t_list *current;

	current = *stack;
	while (len > 0 && current)
	{
		if ((int)(__intptr_t)current->content == max)
			return (1);
		current = current->next;
		len--;
	}
	return (0);
}
