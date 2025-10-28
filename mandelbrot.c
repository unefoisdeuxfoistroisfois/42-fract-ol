#include <stdio.h>

int main(void)
{
    int	width;
    int	height;
    int max_iter;
    int y;
    int x;
    double a;
    double b;
    double zx;
    double zy;
    int iter;
    double tmp;
    
    width = 80;
    height = 40;
    max_iter = 1000;
    
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            // Transformation du pixel en coordonnées complexes
            a = (x - width / 2.0) * 4.0 / width;
            b = (y - height / 2.0) * 2.0 / height;
            
            zx = 0.0;
            zy = 0.0;
            iter = 0;
            
            while (zx * zx + zy * zy < 4.0 && iter < max_iter)
            {
                tmp = zx * zx - zy * zy + a;
                zy = 2.0 * zx * zy + b;
                zx = tmp;
                iter++;
            }
            
            if (iter == max_iter)
                printf(".");   // Le point appartient à l'ensemble
            else
                printf(" ");   // Le point diverge
            
            x++;
        }
        printf("\n");
        y++;
    }
    return (0);
}
