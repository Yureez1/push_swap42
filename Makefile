# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <julien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:27:50 by julien            #+#    #+#              #
#    Updated: 2024/11/19 20:12:54 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
HEADER = push_swap.h

# Fichiers sources
SRCS = push_more.c push_swap.c error.c init.c \
       push.c reverse_rot.c rotate.c swap.c \
       parsing.c utils.c main.c

OBJS = $(SRCS:.c=.o)

# Répertoires pour ft_printf et libft
PRINTF_DIR = ft_printf/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = $(PRINTF_DIR)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Règle principale
all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)
	@echo "Compiling push_swap..."
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "Done !"

# Compilation de ft_printf (qui inclut libft)
$(PRINTF_LIB): $(LIBFT_LIB)
	@echo "Compiling ft_printf..."
	@make -C $(PRINTF_DIR)

# Compilation de libft
$(LIBFT_LIB):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

# Exécution avec ou sans arguments
run: $(NAME)
	@if [ -z "$(ARG)" ]; then \
		./$(NAME); \
	else \
		./$(NAME) $(ARG); \
	fi

# Nettoyage
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Full cleaning..."
	@rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	rm -f ARG*

re: fclean all

.PHONY: all clean fclean re run