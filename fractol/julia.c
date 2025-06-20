#include "fractol.h"

// Calcula iteraciones para el conjunto de Julia
// z = (zx, zy) es punto actual, c = (c_re, c_im) es constante fija
int julia(double zx, double zy, double c_re, double c_im)
{
    int iter = 0;

    while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
    {
        double tmp = zx * zx - zy * zy + c_re;
        zy = 2.0 * zx * zy + c_im;
        zx = tmp;
        iter++;
    }
    return iter;
}
