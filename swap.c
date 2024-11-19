/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:03 by julien            #+#    #+#             */
/*   Updated: 2024/11/19 13:36:39 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, int flag)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	if (flag == 0)
		ft_printf("sa\n");
}

void	swap_b(t_list **stack_b, int flag)
{
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	if (flag == 0)
		ft_printf("sb\n");
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	int flag;

	flag = 1;
	swap_a(stack_a, flag);
	swap_b(stack_b, flag);
	ft_printf("ss\n");
}
