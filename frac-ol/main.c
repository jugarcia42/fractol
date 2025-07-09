/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:15:30 by jugarcia          #+#    #+#             */
/*   Updated: 2025/06/24 15:15:30 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "utils_str.h"

static void	print_usage(void)
{
	ft_putstr("Usage:\n");
	ft_putstr("  ./fractol mandelbrot\n");
	ft_putstr("  ./fractol julia [c_re] [c_im]\n");
	ft_putstr("  ./fractol tricorn\n");
	ft_putstr("Examples:\n");
	ft_putstr("  ./fractol mandelbrot\n");
	ft_putstr("  ./fractol julia -0.7 0.27015\n");
	ft_putstr("  ./fractol tricorn\n");
}

static int	parse_args(t_data *data, int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!ft_strcmp(argv[1], "mandelbrot") && argc == 2)
		data->fractal_type = 0;
	else if (!ft_strcmp(argv[1], "tricorn") && argc == 2)
		data->fractal_type = 2;
	else if (!ft_strcmp(argv[1], "julia") && ((argc == 2) || (argc == 4)))
	{
		data->fractal_type = 1;
		if (argc >= 4)
		{
			data->julia_c_re = ft_atof(argv[2]);
			data->julia_c_im = ft_atof(argv[3]);
		}
	}
	else
		return (0);
	return (1);
}

static void	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->line_length, &data->endian);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (!parse_args(&data, argc, argv))
	{
		print_usage();
		return (1);
	}
	setup_mlx(&data);
	draw_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 4, 1L << 2, mouse_zoom, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
