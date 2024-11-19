/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:00 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 00:30:24 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_list **stack_a, int flag)
{
	t_list	*second_last;
	t_list	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	second_last = NULL;
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	second_last->next = NULL;
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrotate_b(t_list **stack_b, int flag)
{
	t_list	*second_last;
	t_list	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	second_last = NULL;
	last = *stack_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	second_last->next = NULL;
	if (flag == 0)
		ft_printf("rrb\n");
}

void	rrotate_rr(t_list **stack_a, t_list **stack_b)
{
	int	flag;

	flag = 1;
	rrotate_a(stack_a, flag);
	rrotate_b(stack_b, flag);
	ft_printf("rrr\n");
}
