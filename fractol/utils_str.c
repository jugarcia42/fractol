#include <unistd.h>
#include "utils_str.h"

// Compara dos strings, devuelve 0 si son iguales
int ft_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Convierte string a int
int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

// Convierte string a double, sin exponentes, con signo y decimales
double ft_atof(const char *str)
{
    double result = 0.0;
    double frac = 0.0;
    double divisor = 10.0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            frac += (str[i] - '0') / divisor;
            divisor *= 10.0;
            i++;
        }
    }
    return (result + frac) * sign;
}

// Escribe string en salida estándar
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    write(1, str, i);
}
