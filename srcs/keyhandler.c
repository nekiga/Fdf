#include "../fdf.h"

int key_handler(int key)
{
    if (key == ESC_KEY)
        exit(0);
    return (0);
}