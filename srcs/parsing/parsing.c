/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:02:06 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/25 19:02:26 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Check for valid int
int	is_valid_int(char *str)
{
	long	value;
	int		i;

	i = 0;
	if (str[i] == '\0')
		errors_msg("Arguments are empty", NULL);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			errors_msg("Arguments must only contain digits", NULL);
		i++;
	}
	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		errors_msg("Argument is out of int limits", NULL);
	return (SUCCESS);
}

// Check if there is multiple same numbers
int	has_duplicate(int *numbers, int size)
{
	int	i;
	int	j;

	if (size <= 1)
		return (SUCCESS);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				errors_msg("There must be no double", numbers);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

char	**split_args(char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		errors_msg("Error splitting arguments.", NULL);
	return (args);
}

// Parsing args for dup and int numbers
int	*parse_args(int argc, char **argv, int *size)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		errors_msg("Memory allocation failed", NULL);
	while (i < argc - 1)
	{
		if (!is_valid_int(argv[i + 1]))
			errors_msg("Args are not valid", numbers);
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	*size = i;
	if (has_duplicate(numbers, *size) != SUCCESS)
		errors_msg("There must be no double", numbers);
	return (numbers);
}
