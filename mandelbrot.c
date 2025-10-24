#include <stdio.h>

int main() {
    int width = 80, height = 40;
    int max_iter = 1000;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // Transformation du pixel en coordonnées complexes
            double a = (x - width / 2.0) * 4.0 / width;
            double b = (y - height / 2.0) * 2.0 / height;

            double zx = 0.0, zy = 0.0;
            int iter = 0;

            while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
                double tmp = zx * zx - zy * zy + a;
                zy = 2.0 * zx * zy + b;
                zx = tmp;
                iter++;
            }

            if (iter == max_iter)
                printf("#");   // Le point appartient à l'ensemble
            else
                printf(" ");   // Le point diverge
        }
        printf("\n");
    }

    return 0;
}
