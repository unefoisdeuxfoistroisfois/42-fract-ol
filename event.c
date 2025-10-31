#include "fractol.h"

int	ft_close_window(void *param)
{
	(void)param;
	printf("Vous avez quitté");
	exit(0);
	return (0);
}

int	ft_key(int key, void *param)
{
	(void)param;
	if (key == 65307 || key == 53) //linux || macos
		exit(0);
	write (1, "x", 1);
	return (0);
}
