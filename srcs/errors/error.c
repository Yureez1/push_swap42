/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:57:22 by julien            #+#    #+#             */
/*   Updated: 2024/11/18 17:43:20 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_list(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
	tmp = NULL;
}

void	free_all(char **tab, t_list **stack_a, t_list **stack_b, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		free_list(stack_a);
		free_list(stack_b);
	}
	else
	{
		free_list(stack_a);
		free_list(stack_b);
		if (tab != NULL)
			free(tab);
	}
}

void	error_msg(char *msg, t_list **stack, char **tab)
{
	int	i;

	i = 0;
	ft_printf("Error\n%s", msg);
	free_list(stack);
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		free_list(stack);
	}
	exit(EXIT_FAILURE);
}
