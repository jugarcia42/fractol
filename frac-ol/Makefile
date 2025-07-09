NAME        = fractol
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g -Iminilibx-linux
MLX         = -Lminilibx-linux -lmlx -lXext -lX11 -lbsd

SRCS        = main.c mandelbrot.c julia.c utils_str.c hooks.c \
              init.c tricorn.c draw.c
OBJS        = $(SRCS:.c=.o)

MLX_DIR     = minilibx-linux
MLX_REPO    = https://github.com/42Paris/minilibx-linux.git
MLX_LIB     = $(MLX_DIR)/libmlx.a

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone $(MLX_REPO); \
	fi
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@rm -rf $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
