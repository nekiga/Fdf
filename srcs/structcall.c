#include "fdf.h"

t_win *cwin(void)
{
    static t_win *win;

    return (&win);
}

t_img *cimg(void)
{
    static t_img *img;

    return (&img);
}

t_point *cpoint(void)
{
    static t_point *point;

    return (&point);
}

