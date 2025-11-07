/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:29 by britela-          #+#    #+#             */
/*   Updated: 2025/11/07 13:52:52 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		{
			return (1);
		}
		else if (ft_strcmp(argv[1], "Julia") == 0)
		{
			return (2);
		}
		else
		{
			ft_printf("Choisie entre Mandelbrot ou Julia\n");
			ft_printf ("Format correct : %s <NomFractal>", argv[0]);
			return (-1);
		}
	}
	return (-1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx_connection;//car la mlx renvoie un void
	void	*mlx_window;// renovie l'identifiant de la nouvelle fentrre
	int	choice;
	t_mouvement	move;

	choice = ft_args(argc, argv);
	if (choice == -1)
		return (-1);

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "fractol");//ouvrire une fentere
	move.img.img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
	move.img.addr = mlx_get_data_addr(move.img.img, &move.img.bits_per_pixel,
	&move.img.line_length, &move.img.endian);

	move.r1 = -2.5;
	move.r2 = 1.5;
	move.i1 = -2.0;
	move.i2 = 2.0;
	move.mlx = mlx_connection;  // ← AJOUT
	move.win = mlx_window;    

	if (choice == 1)
		mandelbrot(&move.img, &move);
	else if (choice == 2)
		julia();
	
	mlx_put_image_to_window(mlx_connection, mlx_window, move.img.img, 0, 0);
	mlx_hook(mlx_window, 17, 0, ft_close_window, &move);     // Croix
	mlx_mouse_hook(mlx_window, ft_mouse, &move);             // clic/molette
	mlx_key_hook(mlx_window, ft_key, &move); //clavier
	mlx_loop(mlx_connection);

	mlx_destroy_window(mlx_connection,mlx_window);
	free(mlx_connection);
	return (0);
}
