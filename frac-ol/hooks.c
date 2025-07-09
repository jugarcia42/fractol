/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:15:07 by jugarcia          #+#    #+#             */
/*   Updated: 2025/06/24 15:15:07 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65361)
		data->offset_x -= 0.05 / data->zoom;
	else if (keycode == 65363)
		data->offset_x += 0.05 / data->zoom;
	else if (keycode == 65362)
		data->offset_y -= 0.05 / data->zoom;
	else if (keycode == 65364)
		data->offset_y += 0.05 / data->zoom;
	draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img, 0, 0);
	return (0);
}

static void	update_zoom(int x, int y, t_data *data, int zoom_in)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - WIDTH / 2.0)
		/ (0.5 * data->zoom * WIDTH) + data->offset_x;
	mouse_im = (y - HEIGHT / 2.0)
		/ (0.5 * data->zoom * HEIGHT) + data->offset_y;
	if (zoom_in)
		data->zoom *= 1.1;
	else
		data->zoom /= 1.1;
	data->offset_x = mouse_re - (x - WIDTH / 2.0)
		/ (0.5 * data->zoom * WIDTH);
	data->offset_y = mouse_im - (y - HEIGHT / 2.0)
		/ (0.5 * data->zoom * HEIGHT);
}

int	mouse_zoom(int button, int x, int y, t_data *data)
{
	if (button == 4)
		update_zoom(x, y, data, 1);
	else if (button == 5)
		update_zoom(x, y, data, 0);
	draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img, 0, 0);
	return (0);
}
