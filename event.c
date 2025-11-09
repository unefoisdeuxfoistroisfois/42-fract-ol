/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:25:07 by britela-          #+#    #+#             */
/*   Updated: 2025/11/09 14:26:49 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_window(void *param)
{
	(void)param;
	ft_printf ("You have left");
	exit(0);
	return (0);
}

void	ft_move(t_mouvement *move, int key)
{
	double	step;

	step = (move->r2 - move->r1) * 10 / 100;
	if (key == 65362 || key == 126)
	{
		move->i1 = move->i1 - step;
		move->i2 = move->i2 - step;
	}
	else if (key == 65364 || key == 125)
	{
		move->i1 = move->i1 + step;
		move->i2 = move->i2 + step;
	}
	else if (key == 65361 || key == 123)
	{
		move->r1 = move->r1 - step;
		move->r2 = move->r2 - step;
	}
	else if (key == 65363 || key == 124)
	{
		move->r1 = move->r1 + step;
		move->r2 = move->r2 + step;
	}
}

int	ft_key(int key, void *param)
{
	t_mouvement	*move;

	move = (t_mouvement *)param;
	if (key == 65307 || key == 53)
	{
		ft_printf("You have left");
		exit(0);
	}
	else if (key == 65362 || key == 126 || key == 65364 || key == 125
		|| key == 65361 || key == 123 || key == 65363 || key == 124)
	{
		ft_move(move, key);
		if (move->choice == 1)
		{
			mandelbrot(&move->img, move);
		}
		else if (move->choice == 2)
		{
			julia(&move->img, move);
		}
		mlx_put_image_to_window(move->mlx, move->win, move->img.img, 0, 0);
	}
	return (0);
}

void	ft_zoom(t_mouvement *move, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = (move->r1 + move->r2) / 2.0;
	center_i = (move->i1 + move->i2) / 2.0;
	move->r1 = center_r + (move->r1 - center_r) * zoom;
	move->r2 = center_r + (move->r2 - center_r) * zoom;
	move->i1 = center_i + (move->i1 - center_i) * zoom;
	move->i2 = center_i + (move->i2 - center_i) * zoom;
}

int	ft_mouse(int key_mouse, int x, int y, void *param)
{
	double		zoom;
	t_mouvement	*move;

	(void)x;
	(void)y;
	move = (t_mouvement *)param;
	if (key_mouse == 4)
	{
		zoom = 0.9;
	}
	else if (key_mouse == 5)
	{
		zoom = 1.1;
	}
	else
		return (0);
	ft_zoom(move, zoom);
	if (move->choice == 1)
		mandelbrot(&move->img, move);
	else if (move->choice == 2)
		julia(&move->img, move);
	mlx_put_image_to_window(move->mlx, move->win, move->img.img, 0, 0);
	return (0);
}
