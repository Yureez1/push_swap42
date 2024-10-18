/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:02:10 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/18 19:16:50 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include "../ft_printf.h"
#include "../ft_printf/libft/libft.h"

# define INT_MIN −2,147,483,648
# define INT_MAX 2,147,483,647

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}					t_stack;

#endif