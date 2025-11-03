/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:32:34 by britela-          #+#    #+#             */
/*   Updated: 2025/11/03 20:38:19 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_mandelbrot *m, int x, int y)
{
	m->a = (x - WITDH / 2.0) * 4.0 / WITDH;
	m->b = (y - HEIGHT / 2.0) * 2.0 / HEIGHT;
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
	if (m->iter == max_iter)
		m->color = 0xfa9f16;
	else
	{
		m->shade = (255 * m->iter) / max_iter;
		m->color = (m->shade << 16) | (m->shade << 8) | m->shade;
	}
}

void	mandelbrot(t_data *img, int WITDH, int HEIGHT, int max_iter)
{
	int				y;
	int				x;
	t_mandelbrot	m;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WITDH)
		{
			ft_init(&m, x, y, WITDH, HEIGHT);
			ft_calcul(&m, max_iter);
			ft_color(&m, max_iter);
			my_mlx_pixel_put(img, x, y, m.color);
			x++;
		}
		y++;
	}
}
