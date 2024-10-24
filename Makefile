NAME = push_swap

# Compilation and options
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Path to directories
SRC_DIR = srcs
OBJ_DIR = objs
INCLUDES_DIR = inc
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = ft_printf/libft

# Sources files
SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/*.c) \
		$(wildcard $(LIBFT_DIR)/*.c) \

# Objects files
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

INCLUDES = -I$(INCLUDES_DIR) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

# Default setting
all: $(NAME)

# Final compilation program
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[0;32mEverything Compiled\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning objects files
clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

# Rebuilding all
re: fclean all

.PHONY: all clean fclean re