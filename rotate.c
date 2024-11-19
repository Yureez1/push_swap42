/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:02 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 00:32:08 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (flag == 0)
		ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (flag == 0)
		ft_printf("rb\n");
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	int	flag;

	flag = 1;
	rotate_a(stack_a, flag);
	rotate_b(stack_b, flag);
	ft_printf("rr\n");
}
