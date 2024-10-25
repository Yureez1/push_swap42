NAME = push_swap

# Compilation and options
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Path to directories
ALGORITHM_DIR = srcs/algorithm
ERRORS_DIR = srcs/errors
MOVES_DIR = srcs/moves
PARSING_DIR = srcs/parsing
OBJ_DIR = objs
INCLUDES_DIR = inc
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = ft_printf/libft

# Sources files
SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
		$(wildcard $(LIBFT_DIR)/*.c) \
		$(wildcard $(ALGORITHM_DIR)/*.c) \
		$(wildcard $(ERRORS_DIR)/*.c) \
		$(wildcard $(MOVES_DIR)/*.c) \
		$(wildcard $(PARSING_DIR)/*.c) \
		srcs/main.c

# Objects files
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

INCLUDES = -I$(INCLUDES_DIR) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

# Default setting
all: $(NAME)

# Final compilation program
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[0;32mEverything Compiled\033[0m"

$(OBJ_DIR)/%.o: $(ALGORITHM_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(ERRORS_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(MOVES_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARSING_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(FT_PRINTF_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning objects files
clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

# Rebuilding all
re: fclean all

.PHONY: all clean fclean re