#include "fractol.h"

void	mandelbrot(t_data *img, int width, int height, int max_iter)
{
	int				y;
	int				x;
	t_mandelbrot	m;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			m.a = (x - width / 2.0) * 4.0 / width;
			m.b = (y - height / 2.0) * 2.0 / height;
			m.zx = 0.0;
			m.zy = 0.0;
			m.iter = 0;
			while (m.zx * m.zx + m.zy * m.zy < 4.0 && m.iter < max_iter)
			{
				m.new_zx = (m.zx * m.zx - m.zy * m.zy) + m.a;
				m.new_zy = (2.0 * m.zx * m.zy) + m.b;
				m.zx = m.new_zx;
				m.zy = m.new_zy;
				m.iter++;
			}
			if (m.iter == max_iter)
				m.color = 0xfa9f16;
			else
			{
				m.shade = (255 * m.iter) / max_iter;
				m.color = (m.shade << 16) | (m.shade << 8) | m.shade;
			}
			my_mlx_pixel_put(img, x, y, m.color);
			x++;
		}
		y++;
	}
}
