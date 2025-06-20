#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 100

// Estructura principal con todo el estado
typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;

    double  zoom;
    double  offset_x;
    double  offset_y;

    int     fractal_type;  // 0 mandelbrot, 1 julia

    // Constantes para Julia
    double  julia_c_re;
    double  julia_c_im;
}   t_data;

// Prototipos mandelbrot.c
int mandelbrot(double x, double y);

// Prototipos julia.c
int julia(double zx, double zy, double c_re, double c_im);

// Prototipos draw.c
void draw_fractal(t_data *data);
void put_pixel(t_data *data, int x, int y, int color);

// Prototipos hooks.c
int mouse_zoom(int button, int x, int y, t_data *data);
int key_hook(int keycode, t_data *data);
int close_window(t_data *data);

// Prototipos init.c
void init_data(t_data *data);

// Prototipos utils_str.c
int ft_strcmp(const char *s1, const char *s2);
int ft_atoi(const char *str);
double ft_atof(const char *str);
void ft_putstr(char *str);

#endif
