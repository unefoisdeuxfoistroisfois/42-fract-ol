/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:55:19 by britela-          #+#    #+#             */
/*   Updated: 2025/10/03 16:49:10 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	main()
{
	void	*mlx_connection;//car la mlx renvoie un void
	void	*mlx_window;// renovie l'identifiant de la nouvelle fentrre

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
	{
			return (-1);
	}
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "unefoisdeuxfoistroisfois");//ouvrire une fentere
	if (mlx_window == NULL)
	{
			return (-1);
	}
	mlx_pixel_put(mlx_connection, mlx_window, 250, 250, 0xFFFFFF);

	mlx_loop(mlx_connection);
	mlx_destroy_window(mlx_connection,mlx_window);
	free(mlx_connection);
	return (0);
}
