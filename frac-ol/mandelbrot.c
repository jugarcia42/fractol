/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:15:43 by jugarcia          #+#    #+#             */
/*   Updated: 2025/06/24 15:15:43 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x, double y)
{
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	zx = 0.0;
	zy = 0.0;
	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + x;
		zy = 2.0 * zx * zy + y;
		zx = tmp;
		iter++;
	}
	return (iter);
}
