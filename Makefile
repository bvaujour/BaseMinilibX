NAME = game

SRC =	main.c

INCLUDE = game.h

OBJ_DIR = obj
LIBFT_DIR = libs/libft
MLX_DIR = libs/minilibx-linux

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc

LIBS_INCLUDES_PATH = -I$(MLX_DIR) -I$(LIBFT_DIR)
MLX_LINK = -L$(MLX_DIR) -lmlx -lXext -lX11
LIBFT_LINK = -L$(LIBFT_DIR) -lft
MATH_LINK = -lm

CFLAGS = -Wall -Werror -Wextra -g


RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m



$(OBJ_DIR)/%.o: %.c Makefile $(INCLUDE)
	@$(CC) $(CFLAGS) $(LIBS_INCLUDES_PATH) -c $< -o $@

all: $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(NAME) : $(OBJ_DIR) $(OBJ)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(MATH_LINK) $(MLX_LINK) $(LIBFT_LINK) -o $(NAME)
	@echo "$(GREEN)MAKEFILE: COMPILATION DONE.$(RESET)"

clean:
	@rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	@echo "$(BLUE)MAKEFILE: REMOVE OBJECT FILES.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	@echo "$(RED)MAKEFILE: REMOVE EXECUTABLE.$(RESET)"

re: fclean all

.PHONY: all clean fclean re