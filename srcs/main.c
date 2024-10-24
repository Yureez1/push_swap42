/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:12:42 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/24 19:19:28 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*numbers;
	int		stack_size;
	int		chunk_size;
	int		total_chunks;
	int		i;
	int		min;
	int		max;

	if (argc < 2)
		errors_msg("Not enough arguments", NULL);
	numbers = parse_args(argc - 1, &argv[1], &stack_size);
	stack_a = create_stack(numbers, stack_size);
	free(numbers);
	chunk_size = (calculate_chunks_size(stack_size));
	total_chunks = calculate_chunks(stack_size, chunk_size);
	i = 0;
	while (i < total_chunks)
	{
		min = find_min_in_chunk(&stack_a, chunk_size);
		max = find_max_in_chunk(&stack_a, chunk_size);
		i++;
	}
	return (0);
}
