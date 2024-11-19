/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:57:33 by julien            #+#    #+#             */
/*   Updated: 2024/11/18 17:50:34 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reset_index(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
}

void	index_init(t_list **stack_a, int len)
{
	t_list	*tmp;
	t_list	*cur;
	int		min;
	int		i;

	i = 1;
	reset_index(stack_a);
	while (len > 0)
	{
		min = INT_MAX;
		cur = *stack_a;
		while (cur)
		{
			if ((int)(intptr_t)cur->index == 0
				&& (int)(intptr_t)cur->content < min)
			{
				min = (int)(intptr_t)cur->content;
				tmp = cur;
			}
			cur = cur->next;
		}
		tmp->index = i;
		i++;
		len--;
	}
}

t_list	*find_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*min_node;
	int		min;

	min = INT_MAX;
	tmp = *stack;
	min_node = NULL;
	while (tmp)
	{
		if ((int)(intptr_t)tmp->content < min)
		{
			min = (int)(intptr_t)tmp->content;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_list	*find_max(t_list **stack)
{
	t_list	*tmp;
	t_list	*max_node;
	int		max;

	max = INT_MIN;
	tmp = *stack;
	max_node = NULL;
	while (tmp)
	{
		if ((int)(intptr_t)tmp->content > max)
		{
			max = (int)(intptr_t)tmp->content;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

int	find_half(t_list **stack, int max, int len)
{
	t_list	*cur;

	cur = *stack;
	while (len > 0 && cur)
	{
		if ((int)(intptr_t)cur->content <= max)
			return (1);
		cur = cur->next;
		len--;
	}
	return (0);
}
