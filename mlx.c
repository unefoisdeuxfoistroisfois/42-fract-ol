/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:29 by britela-          #+#    #+#             */
/*   Updated: 2025/11/05 18:44:16 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_args(int argc, char **argv)
{
	ft_printf("Choisie entre Mandelbrot ou Julia\n");
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
	t_data	img;

	choice = ft_args(argc, argv);
	if (choice == -1)
		return (-1);

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "fractol");//ouvrire une fentere
	img.img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);

	if (choice == 1)
		mandelbrot(&img, WIDTH, HEIGHT, MAX_ITER);
	else if (choice == 2)
		julia();
	
	mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 0, 0);

	mlx_hook(mlx_window, 17, 0, ft_close_window, NULL);     // Croix
	mlx_key_hook(mlx_window, ft_key, NULL); //clavier
	mlx_loop(mlx_connection);

	mlx_destroy_window(mlx_connection,mlx_window);
	free(mlx_connection);
	return (0);
}
