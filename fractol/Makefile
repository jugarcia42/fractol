NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux
MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lbsd

SRCS = main.c mandelbrot.c julia.c utils_str.c hooks.c init.c draw.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
