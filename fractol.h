/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:12 by britela-          #+#    #+#             */
/*   Updated: 2025/10/31 18:07:56 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#ifndef WIDTH
# define WIDTH 800
#endif

#ifndef HEIGHT
# define HEIGHT 800
#endif

# define MAX_ITER  100

#include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//mandel.c
void	mandelbrot(t_data *img, int width, int height, int max_iter);

//event.c
int	ft_close_window(void *param);
int	ft_key(int key, void *param);

//mlx.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
