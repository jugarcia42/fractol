/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:14:32 by jugarcia          #+#    #+#             */
/*   Updated: 2025/06/24 15:14:32 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int	get_color(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
		return (0x000000);
	r = (int)(sin(0.3 * iter + 0) * 127 + 128);
	g = (int)(sin(0.3 * iter + 2) * 127 + 128);
	b = (int)(sin(0.3 * iter + 4) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

static int	calculate_iter(t_data *data, double re, double im)
{
	if (data->fractal_type == 0)
		return (mandelbrot(re, im));
	else if (data->fractal_type == 1)
		return (julia(re, im, data->julia_c_re, data->julia_c_im));
	else if (data->fractal_type == 2)
		return (tricorn(re, im));
	return (0);
}

static void	draw_pixel(t_data *data, int x, int y)
{
	double	re;
	double	im;
	int		iter;
	int		color;

	re = (x - WIDTH / 2.0)
		/ (0.5 * data->zoom * WIDTH) + data->offset_x;
	im = (y - HEIGHT / 2.0)
		/ (0.5 * data->zoom * HEIGHT) + data->offset_y;
	iter = calculate_iter(data, re, im);
	color = get_color(iter);
	put_pixel(data, x, y, color);
}

void	draw_fractal(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(data, x, y);
			x++;
		}
		y++;
	}
}
