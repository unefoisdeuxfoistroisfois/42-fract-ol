/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:10:02 by britela-          #+#    #+#             */
/*   Updated: 2025/11/10 18:15:53 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clean(t_mouvement *move)
{
	if (move->img.img)
	{
		mlx_destroy_image(move->mlx, move->img.img);
	}
	if (move->win)
	{
		mlx_destroy_window(move->mlx, move->win);
	}
	if (move->mlx)
	{
//		mlx_destroy_display(move->mlx);
		free (move->mlx);
	}
}
