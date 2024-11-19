/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:02:10 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/18 17:48:04 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf/ft_printf.h"
# include "../ft_printf/ft_printf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define ERROR 0
# define SUCCESS 1

# define RED "\033[1;31m"
# define GREY "\033[1;30m"
# define RESET "\033[0m"

// typedef struct s_data
// {
// 	int				content;
// 	int				index;
// 	struct s_data	*next;
// }					t_list;

/********************
*********************
**Sorting algorithm**
*********************
*********************/

int		is_sorted(t_list **stack);
void	push_next(t_list **stack_a, t_list **stack_b);
void	push_more(t_list **stack_a, t_list **stack_b, int *start, int *end);
void	push_two(t_list **stack_a);
void	push_three(t_list **stack_a);
void	push_four(t_list **stack_a, t_list **stack_b);
void	push_five(t_list **stack_a, t_list **stack_b);
void	push_swap(t_list **stack_a, t_list **stack_b);

/*******
********
**Init**
********
********/

int		is_in_list(t_list *stack_a, int content);
void	init_list(char *argv, t_list **stack_a, char **tab);

/********
*********
**Utils**
*********
*********/

void	reset_index(t_list **stack);
void	index_init(t_list **stack_a, int len);
t_list	*find_min(t_list **stack);
t_list	*find_max(t_list **stack);
int		find_half(t_list **stack, int max, int len);

/*********
**********
**Errors**
**********
**********/

void	free_list(t_list **stack);
void	free_all(char **tab, t_list **stack_a, t_list **stack_b, int argc);
void	error_msg(char *msg, t_list **stack, char **tab);

/**********
***********
**Parsing**
***********
***********/

int		is_integer(char *str);
void	check_parameter(char *str, t_list **stack_a, char **tab);

/*******
********
**Swap**
********
********/

void	swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);

/*******
********
**Push**
********
********/

void	push(t_list **src, t_list **dest);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);

/*********
**********
**Rotate**
**********
**********/

void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

/*****************
******************
**Reverse rotate**
******************
******************/

void	reverse_rotate(t_list **stack);
void	rrr(t_list *a, t_list *b);
void	rra(t_list **a);
void	rrb(t_list **b);

#endif