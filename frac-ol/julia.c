/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:15:26 by jugarcia          #+#    #+#             */
/*   Updated: 2025/06/24 15:15:26 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double zx, double zy, double c_re, double c_im)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + c_re;
		zy = 2.0 * zx * zy + c_im;
		zx = tmp;
		iter++;
	}
	return (iter);
}
