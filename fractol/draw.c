#include "fractol.h"

// Colores psicodélicos básicos para iteraciones
static int get_color(int iter)
{
    if (iter == MAX_ITER)
        return 0x000000; // negro para puntos dentro del fractal

    int r = (int)(sin(0.3 * iter + 0) * 127 + 128);
    int g = (int)(sin(0.3 * iter + 2) * 127 + 128);
    int b = (int)(sin(0.3 * iter + 4) * 127 + 128);

    return (r << 16) | (g << 8) | b;
}



// Pone un pixel de color en la imagen
void put_pixel(t_data *data, int x, int y, int color)
{
    char *pixel;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    pixel = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int *)pixel = color;
}

// Dibuja el fractal completo (mandelbrot o julia)
void draw_fractal(t_data *data)
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            // Convertimos píxel a coordenadas complejas ajustadas por zoom y desplazamiento
            double re = (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH) + data->offset_x;
            double im = (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT) + data->offset_y;

            int iter;

            if (data->fractal_type == 0)
                iter = mandelbrot(re, im);
            else if (data->fractal_type == 1)
                iter = julia(re, im, data->julia_c_re, data->julia_c_im);
            else if (data->fractal_type == 2)
                iter = tricorn(re, im);
            int color = get_color(iter);

            put_pixel(data, x, y, color);
        }
    }
}
