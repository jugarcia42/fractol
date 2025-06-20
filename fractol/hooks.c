#include "fractol.h"

// Cierra ventana y termina programa limpiamente
int close_window(t_data *data)
{
    (void)data;
    exit(0);
    return (0);
}

// Maneja teclas para mover y salir
int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307) // ESC
        close_window(data);
    else if (keycode == 65361) // izquierda
        data->offset_x -= 0.05 / data->zoom;
    else if (keycode == 65363) // derecha
        data->offset_x += 0.05 / data->zoom;
    else if (keycode == 65362) // arriba
        data->offset_y -= 0.05 / data->zoom;
    else if (keycode == 65364) // abajo
        data->offset_y += 0.05 / data->zoom;
    draw_fractal(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

// Maneja zoom con rueda ratón, centrando en posición del cursor
int mouse_zoom(int button, int x, int y, t_data *data)
{
    double mouse_re = (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH) + data->offset_x;
    double mouse_im = (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT) + data->offset_y;

    if (button == 4) // rueda arriba -> zoom in
    {
        data->zoom *= 1.1;
        // Ajustar offset para centrar zoom en puntero
        data->offset_x = mouse_re - (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH);
        data->offset_y = mouse_im - (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT);
    }
    else if (button == 5) // rueda abajo -> zoom out
    {
        data->zoom /= 1.1;
        data->offset_x = mouse_re - (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH);
        data->offset_y = mouse_im - (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT);
    }
    draw_fractal(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}
