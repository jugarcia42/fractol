/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:14:55 by jugarcia          #+#    #+#             */
/*   Updated: 2025/06/24 15:14:55 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		fractal_type;
	double	julia_c_re;
	double	julia_c_im;
}	t_data;

int		mandelbrot(double x, double y);
int		julia(double zx, double zy, double c_re, double c_im);
int		tricorn(double x, double y);

void	draw_fractal(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);

int		mouse_zoom(int button, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
int		close_window(t_data *data);

void	init_data(t_data *data);

#endif
