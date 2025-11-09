/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:12:55 by britela-          #+#    #+#             */
/*   Updated: 2025/11/09 14:13:22 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check_mandelbrot(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error: Mandelbrot does not take extra arguments.\n");
		ft_printf("Correct format: %s Mandelbrot\n", argv[0]);
		return (-1);
	}
	return (1);
}

int	ft_check_julia(int argc, char **argv, t_mouvement *move)
{
	if (argc == 4)
	{
		move->julia_cr = ft_atoi_julia(argv[2]);
		move->julia_ci = ft_atoi_julia(argv[3]);
	}
	else if (argc == 2)
	{
		move->julia_cr = -0.7;
		move->julia_ci = 0.27015;
	}
	else
	{
		ft_printf("Correct format: %s Julia <r> <i>\n", argv[0]);
		return (-1);
	}
	return (2);
}

int	ft_args(int argc, char **argv, t_mouvement *move)
{
	if (argc < 2)
	{
		ft_printf("Correct format: %s Mandelbrot\n", argv[0]);
		ft_printf("Correct format: %s Julia <r> <i>\n", argv[0]);
		return (-1);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return (ft_check_mandelbrot(argc, argv));
	else if (ft_strcmp(argv[1], "Julia") == 0)
		return (ft_check_julia(argc, argv, move));
	ft_printf("Correct format: %s Mandelbrot\n", argv[0]);
	ft_printf("Correct format: %s Julia <r> <i>\n", argv[0]);
	return (-1);
}
