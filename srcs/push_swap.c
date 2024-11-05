/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:12:42 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/05 15:20:26 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		stack_size;
	
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && is_valid_int(argv[1]) && ft_atoi(argv[1]) == 1)
		return (0);
	numbers = parse_args(argc - 1, argv + 1, &stack_size);
	if (!numbers)
		errors_msg("Error\n", NULL);
	a = create_stack(numbers, stack_size);
	free(numbers);
	if (!a)
		errors_msg("Error\n", NULL);
	push_chunks_to_b(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
