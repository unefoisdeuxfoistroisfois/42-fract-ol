/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:29 by britela-          #+#    #+#             */
/*   Updated: 2025/11/09 14:15:18 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_fractol(t_mouvement *move, void **mlx, void **win)
{
	*mlx = mlx_init();
	*win = mlx_new_window(*mlx, WIDTH, HEIGHT, "fractol");
	move->img.img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	move->img.addr = mlx_get_data_addr(move->img.img,
			&move->img.bits_per_pixel, &move->img.line_length,
			&move->img.endian);
	move->r1 = -2.5;
	move->r2 = 1.5;
	move->i1 = -2.0;
	move->i2 = 2.0;
	move->mlx = *mlx;
	move->win = *win;
}

void	ft_run_fractol(t_mouvement *move, void *mlx, void *win, int choice)
{
	if (choice == 1)
		mandelbrot(&move->img, move);
	else if (choice == 2)
		julia(&move->img, move);
	mlx_put_image_to_window(mlx, win, move->img.img, 0, 0);
	mlx_hook(win, 17, 0, ft_close_window, move);
	mlx_mouse_hook(win, ft_mouse, move);
	mlx_key_hook(win, ft_key, move);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	void		*mlx_connection;
	void		*mlx_window;
	int			choice;
	t_mouvement	move;

	choice = ft_args(argc, argv, &move);
	if (choice == -1)
		return (-1);
	move.choice = choice;
	ft_init_fractol(&move, &mlx_connection, &mlx_window);
	ft_run_fractol(&move, mlx_connection, mlx_window, choice);
	return (0);
}
