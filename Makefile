NAME = push_swap

# Compilation and options
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Path to directories
ALGORITHM_DIR = srcs/algorithm
ERRORS_DIR = srcs/errors
MOVES_DIR = srcs/moves
PARSING_DIR = srcs/parsing
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = ft_printf/libft
OBJ_DIR = objs
INCLUDES_DIR = inc

# Source files
SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
       $(wildcard $(LIBFT_DIR)/*.c) \
       $(wildcard $(ALGORITHM_DIR)/*.c) \
       $(wildcard $(ERRORS_DIR)/*.c) \
       $(wildcard $(MOVES_DIR)/*.c) \
       $(wildcard $(PARSING_DIR)/*.c) \
       srcs/main.c

# Object files - maps each source file to a corresponding object file in objs/ with subdirectories
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I$(INCLUDES_DIR) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

# Default target
all: $(NAME)

# Final compilation program
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[0;32mEverything Compiled\033[0m"

# Compilation rule for each object file
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Ensure OBJ_DIR exists
$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

# Cleaning object files
clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
