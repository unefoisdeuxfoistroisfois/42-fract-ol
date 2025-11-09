/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:58:12 by britela-          #+#    #+#             */
/*   Updated: 2025/11/09 12:55:59 by britela-         ###   ########.fr       */
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

//structure pour la Mandelbrot
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

// structure pour la Julia
typedef struct s_julia
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
}		t_julia;

//structure pour le deplacement
typedef struct s_mouvement
{
	double	r1;
	double	r2;
	double	i1;
	double	i2;
	double	julia_cr;
	double	julia_ci;
	int	choice;
	void	*mlx;
	void	*win;
	t_data	img;
}	t_mouvement;

//mandel.c
void	mandelbrot(t_data *img, t_mouvement *move);
void	ft_init(t_mandelbrot *m, double x, double y, t_mouvement *move);
void	ft_calcul(t_mandelbrot *m, int max_iter);
void	ft_color(t_mandelbrot *m, int max_iter);

//julia.c
void	julia(t_data *img, t_mouvement *move);
void	ft_julia_init(t_julia *j, double x, double y, t_mouvement *move);
void	ft_julia_calcul(t_julia *j, int max_iter);
void	ft_julia_color(t_julia *j, int max_iter);

//event.c
int	ft_close_window(void *param);
void	ft_move(t_mouvement *move, int key);
int	ft_key(int key, void *param);
void	ft_zoom(t_mouvement *move, double zoom);
int	ft_mouse(int key_mouse, int x, int y, void *param);

//mlx.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	ft_args(int argc, char **argv, t_mouvement *move); 
void	ft_init_fractol(t_mouvement *move, void **mlx, void **win);
void	ft_run_fractol(t_mouvement *move, void *mlx, void *win, int choice);

//libft
int	ft_strcmp(char *s1, char *s2);
double	ft_atoi_julia2(char *str, int i);
double	ft_atoi_julia(char *str);

#endif
