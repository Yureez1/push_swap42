NAME = push_swap

# Compilation and options
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Path to directories
SRC_DIR = srcs
OBJ_DIR = objs
INCLUDES_DIR = inc
FT_PRINTF_DIR = ft_printf

# Sources files
SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/.c) \

# Objects files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

INCLUDES = -Iincludes -I$(FT_PRINTF_DIR)

# Default setting
all: $(NAME)

# Final compilation program
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)
		@echo "\033[0;32mEverything Compiled\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning objects files
clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

# Rebuilding all
re: fclean all

.PHONY: all clean fclean re