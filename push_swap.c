/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:53 by julien            #+#    #+#             */
/*   Updated: 2024/11/19 13:34:26 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_two(t_list **stack_a)
{
	int		first;
	int		last;
	t_list	*tmp;

	tmp = (*stack_a);
	first = (int)(__intptr_t)(tmp->content);
	tmp = tmp->next;
	last = (int)(__intptr_t)(tmp->content);
	if (first > last)
		swap_a(stack_a, 0);
}

void	ps_three(t_list **stack_a)
{
	int	first;
	int	last;
	int	mid;

	first = (int)(__intptr_t)((*stack_a)->content);
	mid = (int)(__intptr_t)((*stack_a)->next->content);
	last = (int)(__intptr_t)((*stack_a)->next->next->content);
	if (mid > first && mid > last && last > first)
	{
		swap_a(stack_a, 0);
		rotate_a(stack_a, 0);
	}
	if (first > mid && mid < last && last > first)
		swap_a(stack_a, 0);
	if (first > mid && mid < last && last < first)
		rotate_a(stack_a, 0);
	if (mid > last && mid > first && last < first)
		rrotate_a(stack_a, 0);
	if (first > mid && mid > last && first > last)
	{
		rotate_a(stack_a, 0);
		swap_a(stack_a, 0);
	}
	return ;
}

void	ps_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(stack_a);
	min_nbr = (int)(__intptr_t)min->content;
	if ((int)(__intptr_t)(*stack_a)->content == min_nbr)
		push_b(stack_a, stack_b);
	else if ((int)(__intptr_t)(*stack_a)->next->content == min_nbr)
	{
		rotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((int)(__intptr_t)(*stack_a)->content != min_nbr)
			rrotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	if (!sorted(stack_a))
		ps_three(stack_a);
	push_a(stack_a, stack_b);
}

void	ps_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(stack_a);
	min_nbr = (int)(__intptr_t)min->content;
	if ((int)(__intptr_t)(*stack_a)->content == min_nbr)
		push_b(stack_a, stack_b);
	else if ((int)(__intptr_t)(*stack_a)->next->content == min_nbr)
	{
		rotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	else
	{
		while ((int)(__intptr_t)(*stack_a)->content != min_nbr)
			rrotate_a(stack_a, 0);
		push_b(stack_a, stack_b);
	}
	if (!sorted(stack_a))
		ps_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int start;
	int end;
	int len;

	len = ft_lstsize(*stack_a);
	start = 0;
	end = 15;
	if (len == 1)
		return ;
	else if (len == 2)
		ps_two(stack_a);
	else if (len == 3)
		ps_three(stack_a);
	else if (len == 4)
		ps_four(stack_a, stack_b);
	else if (len == 5)
		ps_five(stack_a, stack_b);
	else if (len > 3)
		ps_more(stack_a, stack_b, &start, &end);
}
