#include "fractol.h"

int tricorn(double x, double y)
{
    double zx = 0.0;
    double zy = 0.0;
    int iter = 0;

    while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
    {
        double temp = zx * zx - zy * zy + x;
        zy = -2.0 * zx * zy + y;  // nota el signo menos aquí
        zx = temp;
        iter++;
    }
    return iter;
}
