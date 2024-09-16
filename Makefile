CC = cc
NAME = cub
NAME_BONUS = cub_bonus

SRC = ./src/main.c \
      ./src/parsing/parsing.c \
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
      ./src/execution/draw_images.c


LIB = ./includes/cub.h ./includes/includes.h ./includes/macros.h ./includes/prototypes.h \
      ./includes/structures.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -lXext -lX11 -lm $(LIBFT) -o $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus
