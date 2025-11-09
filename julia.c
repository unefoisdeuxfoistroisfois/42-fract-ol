/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:07:12 by britela-          #+#    #+#             */
/*   Updated: 2025/11/10 00:45:04 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_init(t_julia *j, double x, double y, t_mouvement *move)
{
	j->zx = move->r1 + x * (move->r2 - move->r1) / WIDTH;
	j->zy = move->i1 + y * (move->i2 - move->i1) / HEIGHT;
	j->a = move->julia_cr;
	j->b = move->julia_ci;
	j->iter = 0;
}

void	ft_julia_calcul(t_julia *j, int max_iter)
{
	while (j->zx * j->zx + j->zy * j->zy < 4.0 && j->iter < max_iter)
	{
		j->new_zx = (j->zx * j->zx - j->zy * j->zy) + j->a;
		j->new_zy = (2.0 * j->zx * j->zy) + j->b;
		j->zx = j->new_zx;
		j->zy = j->new_zy;
		j->iter++;
	}
}

void	ft_julia_color(t_julia *j, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (j->iter == max_iter)
	{
		j->color = 0x000000;
	}
	else
	{
		r = (j->iter * 8) % 256;
		g = (j->iter * 4) % 256;
		b = (j->iter * 2) % 256;
		j->color = (r << 16) | (g << 8) | b;
	}
}

void	julia(t_data *img, t_mouvement *move)
{
	double		y;
	double		x;
	t_julia		j;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_julia_init(&j, x, y, move);
			ft_julia_calcul(&j, MAX_ITER);
			ft_julia_color(&j, MAX_ITER);
			my_mlx_pixel_put(img, x, y, j.color);
			x++;
		}
		y++;
	}
}
