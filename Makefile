GREEN = \033[1;3;32m
RED = \033[1;3;31m
YELLOW=\033[1;3;33m
RESET = \033[0m
MAGENTA = \033[1;35m
BLUE = \033[34;1;3m

CC = cc
NAME = cub
NAME_BONUS = cub_bonus

SRC = ./src/main.c \
	./src/parsing/ft_parsing.c \
	./src/execution/reset_values.c \
	./src/execution/background_drawing.c \
	./src/execution/main_execution.c \
	./src/execution/movement_logic.c \
	./src/execution/error_handling.c \
	./src/execution/default_configuration.c \
	./src/execution/key_event_processing.c \
	./src/execution/render_engine.c \
	./src/execution/asset_manager.c \
	./src/execution/raycasting.c \
	./src/execution/raycast_math.c \
	./src/execution/draw_images.c \
	./src/execution/ray_hit_the_wall.c \
	./src/execution/handle_mouse.c \
	./src/parsing/ft_normalize_map.c \
	./src/parsing/ft_verify_map.c \
	./src/parsing/ft_utils.c \
	./src/parsing/ft_verify_floor_ceil.c \
	./src/parsing/ft_verify_textures.c \
	./src/parsing/ft_verify_data.c \
	./src/parsing/ft_verify_content.c \
	./src/parsing/ft_free_parsing.c \
	./src/parsing/upload_content.c \
	./src/parsing/utils.c \
	./src/parsing/get_next_line.c \
	./src/parsing/get_next_line_utils.c

LIB = ./includes/cub.h ./includes/includes.h ./includes/macros.h ./includes/prototypes.h \
	./includes/structures.h

CFLAGS = -Wall -Wextra  -Werror #-fsanitize=address -g
LIBFT_PATH = ./libft
MLX_PATH = ./minilibx
LIBFT = $(LIBFT_PATH)/libft.a
MLX= $(MLX_PATH)/libmlx.a
OBJ = $(SRC:.c=.o)

all: $(MLX) $(LIBFT) $(NAME)
	@echo "";

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx -lXext -lX11 -lm $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)\t\t✓ $(NAME)$(RESET)"
	@echo "$(MAGENTA)Usage:\n\t$(YELLOW)./cub map.cub$(RESET)"
	

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)\t\t✓ libft$(RESET)"
$(MLX):
	@$(MAKE) -C $(MLX_PATH) > /dev/null
	@echo "$(GREEN)\t\t✓ mlx$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -Iminilibx-linux -O3 -c $< -o $@


clean:
	@rm -f $(OBJ)
	@echo "$(RED)\t\t✓ deleted objects $(NAME)$(RESET)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted objects libft$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)\t\t✓ deleted $(NAME)$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@$(MAKE) clean -C $(MLX_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted libft$(RESET)"
	@echo "$(RED)\t\t✓ deleted mlx$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
