/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:02:10 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/22 16:41:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define ERROR 0;
# define SUCCESS 1;

# define RED "\033[1;31m"
# define GREY "\033[1;30m"
# define RESET "\033[0m"

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}					t_stack;

#endif