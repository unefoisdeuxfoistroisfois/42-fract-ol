/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:55:19 by britela-          #+#    #+#             */
/*   Updated: 2025/10/01 14:20:49 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	main()
{
	void	*mlx_ptr;//car la mlx renvoie un void
	void	*win_ptr;// renovie l'identifiant de la nouvelle fentrre

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
			return (-1);
	}
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "unefoisdeuxfoistroisfois");//ouvrire une fentere
	if (win_ptr == NULL)
	{
			return (-1);
	}
	mlx_loop(mlx_ptr);
	
	return (0);
}
