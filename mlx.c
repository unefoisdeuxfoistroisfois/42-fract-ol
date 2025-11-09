/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:29 by britela-          #+#    #+#             */
/*   Updated: 2025/11/09 12:56:26 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_args(int argc, char **argv, t_mouvement *move)
{
	if (argc < 2)
	{
		ft_printf("Format correct : %s Mandelbrot\n", argv[0]);
		ft_printf("Format correct : %s Julia <r> <i>\n", argv[0]);
		return (-1);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		if (argc == 4)
		{
			move->julia_cr = ft_atoi_julia(argv[2]);
			move->julia_ci = ft_atoi_julia(argv[3]);
		}
		else
		{
			move->julia_cr = -0.7;
			move->julia_ci = 0.27015;
		}
		return (2);
	}
	ft_printf("Format correct : %s Mandelbrot\n", argv[0]);
	ft_printf("Format correct : %s Julia <r> <i>\n", argv[0]);
	return (-1);
}


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
