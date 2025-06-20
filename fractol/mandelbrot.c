#include "fractol.h"

// Calcula iteraciones para el conjunto de Mandelbrot
int mandelbrot(double x, double y)
{
    double zx = 0.0;
    double zy = 0.0;
    int iter = 0;

    // Iteramos mientras el valor esté dentro del círculo de radio 2 y no se supere max iteraciones
    while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
    {
        double tmp = zx * zx - zy * zy + x;
        zy = 2.0 * zx * zy + y;
        zx = tmp;
        iter++;
    }
    return iter;
}
