GREEN = \033[1;3;32m
RED = \033[1;3;31m
BLUE = \033[34m
RESET = \033[0m
MAGENTA = \033[1;35m

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

CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "$(MAGENTA)>>>> START BUILDING CUB3D <<<<$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx -lXext -lX11 -lm $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\t\t✓ $(NAME)$(RESET)"

$(LIBFT):
	@echo "$(MAGENTA)>>>> START BUILDING LIBFT <<<<$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)\t\t✓ LIBFT$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -Iminilibx-linux -O3 -c $< -o $@

clean:
	@echo "$(MAGENTA)>>>> Start removing $(NAME) Object files <<<<$(RESET)"
	@rm -f $(OBJ)
	@echo "$(RED)\t\t✓ deleted objects $(NAME)$(RESET)"
	@echo "$(MAGENTA)>>>> Start removing libft Object files <<<<$(RESET)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted objects libft$(RESET)"

fclean: clean
	@echo "$(MAGENTA)>>>> Start removing $(NAME) <<<<$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)\t\t✓ deleted $(NAME)$(RESET)"
	@echo "$(MAGENTA)>>>> Start removing libft <<<<$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@echo "$(RED)\t\t✓ deleted libft$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
