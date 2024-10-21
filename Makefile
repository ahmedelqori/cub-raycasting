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

CFLAGS = -Wall -Wextra #-Werror
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx -lXext -lX11 -lm $(LIBFT) -o $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx-linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus
