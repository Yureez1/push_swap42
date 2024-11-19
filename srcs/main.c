/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:57:34 by julien            #+#    #+#             */
/*   Updated: 2024/11/18 17:51:48 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	char **tab;
	t_list *stack_a;
	t_list *stack_b;
	int i;

	tab = NULL;
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (tab[i])
			check_parameter(tab[i++], &stack_a, tab);
	}
	else if (argc > 2)
	{
		while (argv[i++])
			check_parameter(argv[i++], &stack_a, tab);
	}
	if (!is_sorted(&stack_a))
		pa(&stack_a, &stack_b);
	free_all(tab, &stack_a, &stack_b, argc);
	exit(EXIT_SUCCESS);
	return (0);
}
