/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:57:20 by julien            #+#    #+#             */
/*   Updated: 2024/11/18 17:42:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_two(t_list **stack_a)
{
	int		first;
	int		last;
	t_list	*tmp;

	tmp = (*stack_a);
	first = (int)(intptr_t)(tmp->content);
	tmp = tmp->next;
	last = (int)(intptr_t)(tmp->content);
	if (first > last)
		sb(stack_a);
}

void	push_three(t_list **stack_a)
{
	int	first;
	int	mid;
	int	last;

	first = (int)(intptr_t)((*stack_a)->content);
	mid = (int)(intptr_t)((*stack_a)->next->content);
	last = (int)(intptr_t)((*stack_a)->next->content);
	if (mid > first && mid > last && last > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (first > mid && mid < last && last > first)
		sa(stack_a);
	if (first > mid && mid < last && last < first)
		ra(stack_a);
	if (mid > last && mid > first && last < first)
		rra(stack_a);
	if (first > mid && mid > last && first > last)
	{
		ra(stack_a);
		sa(stack_a);
	}
	return ;
}

void	push_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(stack_a);
	min_nbr = (int)(intptr_t)(min->content);
	if ((int)(intptr_t)(*stack_a)->content == min_nbr)
		pb(stack_a, stack_b);
	else if ((int)(intptr_t)(*stack_a)->next->content == min_nbr)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((int)(intptr_t)(*stack_a)->content != min_nbr)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		push_three(stack_a);
	pa(stack_a, stack_b);
}

void	push_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(stack_a);
	min_nbr = (int)(intptr_t)min->content;
	if ((int)(intptr_t)(*stack_a)->content == min_nbr)
		pb(stack_a, stack_b);
	else if ((int)(intptr_t)(*stack_a)->next->content == min_nbr)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((int)(intptr_t)(*stack_a)->content != min_nbr)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		push_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	start;
	int	end;
	int	len;

	len = ft_lstsize(*stack_a);
	start = 0;
	end = 15;
	if (len == 1)
		return ;
	else if (len == 2)
		push_two(stack_a);
	else if (len == 3)
		push_three(stack_a);
	else if (len == 4)
		push_four(stack_a, stack_b);
	else if (len == 5)
		push_five(stack_a, stack_b);
	else if (len > 3)
		push_more(stack_a, stack_b, &start, &end);
}
