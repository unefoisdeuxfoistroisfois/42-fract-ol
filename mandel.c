#include "fractol.h"

void	mandelbrot(t_data *img, int width, int height, int max_iter)
{
	int		y;
	int		x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			a = (x - width / 2.0) * 4.0 / width;
			b = (y - height / 2.0) * 2.0 / height;

			zx = 0.0;
			zy = 0.0;
			iter = 0;
			while (zx * zx + zy * zy < 2 * 2 && iter < max_iter)
			{
				new_zx = (zx * zx - zy * zy) + a;  // x_{n+1}
				new_zy = (2.0 * zx * zy) + b;      // y_{n+1}
				zx = new_zx;
				zy = new_zy;
				iter++;
			}
			if (iter == max_iter)
				color = 0xfa9f16;
			else
			{
				shade = (255 * iter) / max_iter;       // dégradé de gris
				color = (shade << 16) | (shade << 8) | shade;
			}
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
