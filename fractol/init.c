#include "fractol.h"

// Inicializa datos por defecto
void init_data(t_data *data)
{
    data->zoom = 1.0;
    data->offset_x = 0.0;
    data->offset_y = 0.0;

    // Julia por defecto con constante c = -0.7 + 0.27015i
    data->julia_c_re = -0.7;
    data->julia_c_im = 0.27015;
}
