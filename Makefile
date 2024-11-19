# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <julien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 17:00:47 by julien            #+#    #+#              #
#    Updated: 2024/11/18 17:55:27 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
HEADER = push_swap.h
SRCS = srcs/algs/push_more.c srcs/algs/push_swap.c srcs/errors/error.c srcs/init/init.c srcs/moves/push.c srcs/moves/reverse_rot.c srcs/moves/rotate.c srcs/moves/swap.c srcs/parsing/parsing.c srcs/utils/utils.c srcs/main.c

OBJS = $(SRCS:.c=.o)

ARG ?=

#inclu ft_printf
PRINTF_DIR = ft_printf/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

#inclu libft
LIBFT_DIR = ft_printf/ft_printf/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(PRINTF_LIB) $(LIBFT_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER)

$(NAME): $(OBJS) $(PRINTF_LIB)
	@echo "Compiling push_swap..."
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "Done !"

run: $(NAME)
	@if [ -z "$(ARG)"]; then \
		./$(NAME); \
	else \
		./$(NAME) $(ARG); \
	fi

$(PRINTF_LIB):
	@echo "Compiling ft_printf..."
	@make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJS)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Full cleaning..."
	@rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	rm ARG*

re: fclean all

.PHONY: all clean fclean re