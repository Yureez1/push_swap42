/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:02:06 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/21 16:29:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// Check for valid int
int	is_valid_int(char *str)
{
	long	value;

	value = ft_atol(str);
	if (str[i] == '\0')
		errors_msg("Arguments are empty");
	while (str[i])
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			errors_msg("It has to be just numbers");
	i++;
	if (value < INT_MIN || value > INT_MAX)
		errors_msg("An argument is not within the limit of int");
	return (SUCCESS);
}

// Check if there is multiple same numbers
int	has_duplicate(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				errors_msg("There must be no double");
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

// Parsing args for dup and int numbers
int	*parse_args(int argc, char **argv, int *size)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (NULL);
	while (i < argc - 1)
	{
		if (!is_valid_int(argc[i]))
			errors_msg("Args are not valid");
		numbers[i] = ft_atoi(argv[i]);
		i++;
	}
	if (has_duplicate(numbers, argc - 1))
		errors_msg("There must be no double");
	*size = argc - 1;
	return (numbers);
}
