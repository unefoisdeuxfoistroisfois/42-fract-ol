/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:25:07 by britela-          #+#    #+#             */
/*   Updated: 2025/11/07 14:09:25 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_window(void *param)
{
	(void)param;
	ft_printf("Vous avez quitté\n");
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
		move->r1 = move->i1 - step;
		move->r2 = move->i2 - step;
	}
	else if (key == 65363 || key == 124)
	{
		move->r1 = move->i1 + step;
		move->r2 = move->i2 + step;
	}
}

int	ft_key(int key, void *param)
{
	t_mouvement	*move;

	move = (t_mouvement *)param;
	if (key == 65307 || key == 53)
	{
		ft_printf("Vous avez quitté\n");
		exit(0);
	}
	else if (key == 65362 || key == 126 || key == 65364 || key == 125 ||
		key == 65361 || key == 123 || key == 65363 || key == 124)
	{
		ft_move(move, key);
		mandelbrot(&move->img, move);
		mlx_put_image_to_window(move->mlx, move->win, move->img.img, 0, 0);
	}
	return (0);
}
int	ft_mouse(int key_mouse, int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;
	if (key_mouse == 4)
		ft_printf("ZOOM +");
	else if (key_mouse == 5)
		ft_printf("ZOMM -");
	return (0);
}
