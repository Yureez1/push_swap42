/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:57:25 by julien            #+#    #+#             */
/*   Updated: 2024/11/18 17:44:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_in_list(t_list *stack_a, int content)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if ((int)(intptr_t)(stack_a)->content == content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	init_list(char *argv, t_list **stack_a, char **tab)
{
	static t_list	*tmp;
	int				num;

	num = ft_atoi(argv);
	if (is_in_list(*stack_a, num))
		error_msg("There must be no double.", stack_a, tab);
	tmp = ft_lstnew((void *)(intptr_t)num);
	if (!tmp)
		error_msg("Failed to create new node.", stack_a, tab);
	ft_lstadd_back(stack_a, tmp);
}
