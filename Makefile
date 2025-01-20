NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = src/general_utils/utils_1.c \
      src/lexer/lexer.c \
      src/minishell/tools.c \
      src/minishell/utils_1.c \
      src/minishell/utils_2.c \
      src/parsing/parser.c \
      src/builtin/export/export_utils_1.c

MAIN = main.c

OBJ_DIR = build

OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -Ilibft/includes -Iincludes

LIBFT = libft/libft.a

# Target to build everything
all: $(NAME) 

# Build libft
$(LIBFT):
	@$(MAKE) -C libft

# Rule to compile object files
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to build the final executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

# Clean intermediate files
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C libft clean

# Clean all built files
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
