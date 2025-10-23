#include "mlx.h"
#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	carre(t_data *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < 100)  // De 0 à 99 = 100 pixels
	{
		x = 0;
		while (x < 100)  // De 0 à 99 = 100 pixels
		{
			my_mlx_pixel_put(img, x, y,0x004287f5 );
			x++;
		}
		y++;
	}
}

int	main()
{
	void	*mlx_connection;//car la mlx renvoie un void
	void	*mlx_window;// renovie l'identifiant de la nouvelle fentrre
	t_data	img;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
	{
			return (-1);
	}
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "unefoisdeuxfoistroisfois");//ouvrire une fentere
	if (mlx_window == NULL)
	{
			return (-1);
	}
	img.img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	carre(&img);


	mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 0, 0);

	mlx_loop(mlx_connection);

	mlx_destroy_window(mlx_connection,mlx_window);
	free(mlx_connection);
	return (0);
}
