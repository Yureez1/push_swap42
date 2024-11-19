/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:55 by julien            #+#    #+#             */
/*   Updated: 2024/11/19 20:15:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>

/*stack*/
// typedef struct s_data
// {
// 	int				content;
// 	int				index;
// 	struct s_data	*next;
// }					t_list;

void	error_mes(char *str, t_list **stack_a, char **tab);
void	free_all(char **tab, t_list **stack_a, t_list **stack_b, int argc);
void	init_lst(char *argv, t_list **stack_a, char **tab);
void	swap_a(t_list **stack_a, int flag);
void	swap_b(t_list **stack_b, int flag);
void	swap_ss(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a, int flag);
void	rotate_b(t_list **stack_b, int flag);
void	rotate_rr(t_list **stack_a, t_list **stack_b);
void	rrotate_a(t_list **stack_a, int flag);
void	rrotate_b(t_list **stack_b, int flag);
void	rrotate_rr(t_list **stack_a, t_list **stack_b);
void	push_swap(t_list **stack_a, t_list **stack_b);

int		find_half(t_list **stack, int max, int len);
t_list	*find_max(t_list **stack);
t_list	*find_min(t_list **stack);
void	init_index(t_list **stack_a, int len);
void	index_zero(t_list **stack);
void	ps_more(t_list **stack_a, t_list **stack_b, int *start, int *end);
void	push_next(t_list **stack_a, t_list **stack_b);
int		sorted(t_list **stack);

#endif