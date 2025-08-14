/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:55:19 by britela-          #+#    #+#             */
/*   Updated: 2025/08/14 17:55:32 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main()
{
	void	*mlx_ptr;//car la mlx renvoie un void
	void	*win_ptr;// renovie l'identifiant de la nouvelle fentrre

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Bradley");//ouvrire une fentere
	mlx_loop(mlx_ptr);
	
	return (0);
}
