/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:29 by britela-          #+#    #+#             */
/*   Updated: 2025/10/29 17:05:02 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close_window(void *param)
{
	(void)param;
	printf("Croix cliqué\n");
	exit(0);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_key(int key, void *param)
{
	(void)param;
	if (key == 65307 || key == 53) //linux || macos
		exit(0);
	ft_putchar('x');
	return (0);
}

int	main()
{
	void	*mlx_connection;//car la mlx renvoie un void
	void	*mlx_window;// renovie l'identifiant de la nouvelle fentrre
	t_data	img;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
	{
			return (-1);
	}
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "fractol");//ouvrire une fentere
	if (mlx_window == NULL)
	{
			return (-1);
	}
	img.img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);

	//Mandelbrot
//	mandelbrot(&img);
	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);

	mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 0, 0);

	mlx_hook(mlx_window, 17, 0, ft_close_window, NULL);     // Croix
	mlx_key_hook(mlx_window, , (void *)0); //clavier
	mlx_loop(mlx_connection);

	mlx_destroy_window(mlx_connection,mlx_window);
	free(mlx_connection);
	return (0);
}
