/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:02:10 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/05 15:07:36 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf.h"
# include "../ft_printf/libft/libft.h"
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

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/********************
*********************
**Sorting algorithm**
*********************
*********************/

t_stack				*create_stack(int *numbers, int stack_size);
int					calculate_chunks_size(int stack_size);
int					calculate_chunks(int stack_size, int chunk_size);
int					find_max_in_chunk(t_stack **stack, int chunk_size);
int					find_min_in_chunk(t_stack **stack, int chunk_size);

/*******************
********************
**Stack Operations**
********************
********************/

void				push_min_max_to_b(t_stack **a, t_stack **b, int chunk_size);
void				sort_and_push_back_to_a(t_stack **a, t_stack **b);
void				push_chunks_to_b(t_stack **a, t_stack **b, int stack_size);
void				free_stack(t_stack **stack);

/*********
**********
**Errors**
**********
**********/

int					errors_msg(char *message, int *numbers);

/*******
********
**Swap**
********
********/

void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);

/*******
********
**Push**
********
********/

void				push(t_stack **src, t_stack **dest);
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);

/*********
**********
**Rotate**
**********
**********/

void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
/*****************
******************
**Reverse rotate**
******************
******************/

void				reverse_rotate(t_stack **stack);
void				rrr(t_stack *a, t_stack *b);
void				rra(t_stack **a);
void				rrb(t_stack **b);

/**********
***********
**Parsing**
***********
***********/

int					is_valid_int(char *str);
int					has_duplicate(int *numbers, int size);
char				**split_args(char *arg);
int					*parse_args(int argc, char **argv, int *size);
int					is_sorted(int *numbers, int size);

#endif