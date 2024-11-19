/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:42 by julien            #+#    #+#             */
/*   Updated: 2024/11/20 00:30:48 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
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
		free_lst(stack_a);
		free_lst(stack_b);
	}
	else
	{
		free_lst(stack_a);
		free_lst(stack_b);
		if (tab != NULL)
			free(tab);
	}
}

void	error_mes(char *str, t_list **stack_a, char **tab)
{
	int	i;

	ft_printf("Error.\n%s", str);
	free_lst(stack_a);
	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		free_lst(stack_a);
	}
	exit(EXIT_FAILURE);
}
