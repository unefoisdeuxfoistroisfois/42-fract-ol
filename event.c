/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:25:07 by britela-          #+#    #+#             */
/*   Updated: 2025/11/06 12:14:48 by britela-         ###   ########.fr       */
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

int	ft_key(int key, void *param)
{
	(void)param;
	if (key == 65307 || key == 53) //linux || macos
	{
		printf("Vous avez quitté\n");
		exit(0);
	}
	else if (key == 65362|| key == 126)
		ft_printf ("HAUT\n");
	else if (key == 65361 || key == 123)
		ft_printf ("GAUCHE\n");
	else if (key == 65363 || key == 124)
		ft_printf ("DROITE\n");
	else if (key == 65364|| key == 125)
		ft_printf ("BAS\n");
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
