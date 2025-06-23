#include "fractol.h"
#include "utils_str.h"

static void print_usage(void)
{
    ft_putstr("Usage:\n");
    ft_putstr("  ./fractol mandelbrot\n");
    ft_putstr("  ./fractol julia [c_re] [c_im]\n");
    ft_putstr("  ./fractol tricorn\n");
    ft_putstr("Examples:\n");
    ft_putstr("  ./fractol mandelbrot\n");
    ft_putstr("  ./fractol julia -0.7 0.27015\n");
    ft_putstr("  ./fractol tricorn\n");
}

// Parsea argumentos para elegir fractal y parámetros Julia
static int parse_args(t_data *data, int argc, char **argv)
{
    if (argc < 2)
        return (0);
    if (!ft_strcmp(argv[1], "mandelbrot"))
        data->fractal_type = 0;
    else if (!ft_strcmp(argv[1], "tricorn"))
        data->fractal_type = 2;
    else if (!ft_strcmp(argv[1], "julia"))
    {
        data->fractal_type = 1;
        if (argc >= 4)
        {
            data->julia_c_re = ft_atof(argv[2]);
            data->julia_c_im = ft_atof(argv[3]);
        }
    }
    else
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_data data;

    init_data(&data);

    if (!parse_args(&data, argc, argv))
    {
        print_usage();
        return (1);
    }

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fractol");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);

    draw_fractal(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    mlx_hook(data.win, 2, 1L << 0, key_hook, &data); // teclado
    mlx_hook(data.win, 4, 1L << 2, mouse_zoom, &data); // ratón
    mlx_hook(data.win, 17, 0, close_window, &data); // cerrar ventana

    mlx_loop(data.mlx);

    return (0);
}
