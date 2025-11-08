/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:12 by britela-          #+#    #+#             */
/*   Updated: 2025/11/08 15:48:29 by britela-         ###   ########.fr       */
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
#include "ft_printf/ft_printf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

//structure pour la mandelbrot
typedef struct	s_mandelbrot
{
	double	a;
	double	b;
	double	zx;
	double	zy;
	double	new_zx;
	double	new_zy;
	int	iter;
	int	color;
	int	shade;
}		t_mandelbrot;

//structure pour le deplacement
typedef struct s_mouvement
{
	double	r1;
	double	r2;
	double	i1;
	double	i2;
	void	*mlx;
	void	*win;
	t_data	img;
}	t_mouvement;

//mandel.c
void	mandelbrot(t_data *img, t_mouvement *move);
void	ft_init(t_mandelbrot *m, double x, double y, t_mouvement *move);
void	ft_calcul(t_mandelbrot *m, int max_iter);
void	ft_color(t_mandelbrot *m, int max_iter);

//julia .c
void	julia();

//event.c
int	ft_close_window(void *param);
void	ft_move(t_mouvement *move, int key);
int	ft_key(int key, void *param);
void	ft_zoom(t_mouvement *move, double zoom);
int	ft_mouse(int key_mouse, int x, int y, void *param);

//mlx.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	ft_args(int argc, char **argv);

//libft
int	ft_strcmp(char *s1, char *s2);
#endif
