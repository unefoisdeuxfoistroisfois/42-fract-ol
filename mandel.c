/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:32:34 by britela-          #+#    #+#             */
/*   Updated: 2025/11/10 00:19:12 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_mandelbrot *m, double x, double y, t_mouvement *move)
{
	m->a = move->r1 + x * (move->r2 - move->r1) / WIDTH;
	m->b = move->i1 + y * (move->i2 - move->i1) / HEIGHT;
	m->zx = 0.0;
	m->zy = 0.0;
	m->iter = 0;
}

void	ft_calcul(t_mandelbrot *m, int max_iter)
{
	while (m->zx * m->zx + m->zy * m->zy < 4.0 && m->iter < max_iter)
	{
		m->new_zx = (m->zx * m->zx - m->zy * m->zy) + m->a;
		m->new_zy = (2.0 * m->zx * m->zy) + m->b;
		m->zx = m->new_zx;
		m->zy = m->new_zy;
		m->iter++;
	}
}

void	ft_color(t_mandelbrot *m, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (m->iter == max_iter)
	{
		m->color = 0x000000;
	}
	else
	{
		r = (m->iter * 32) % 256;
		g = (m->iter * 16) % 256;
		b = (m->iter * 48) % 256;
		m->color = (r << 16) | (g << 8) | b;
	}
}

void	mandelbrot(t_data *img, t_mouvement *move)
{
	double			y;
	double			x;
	t_mandelbrot	m;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_init(&m, x, y, move);
			ft_calcul(&m, MAX_ITER);
			ft_color(&m, MAX_ITER);
			my_mlx_pixel_put(img, x, y, m.color);
			x++;
		}
		y++;
	}
}
