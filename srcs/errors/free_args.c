/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:26:05 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/05 15:42:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_all(t_stack **a, t_stack **b, char **argv, int string)
{
	free_stack(a);
	free_stack(b);
	if (string == 1)
	{
		free_split(argv);
		argv = NULL;
	}
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !(*tab))
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_stack **stack)
{
	t_stack *temp;
	t_stack *cur;

	if (!stack)
		return ;
	cur = *stack;
	while (cur)
	{
		temp = cur->next;
		cur->value = 0;
		free(cur);
		cur = temp;
	}
	*stack = NULL;
}
