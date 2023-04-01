#include "../fdf.h"

int main(void)
{
    
  


    
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "SLAY");
    data.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
    
    draw_line(200, 201, 600,600, &data);
    my_mlx_pixel_put(&data, 30, 30 , GREEN);
    mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
    mlx_key_hook(mlx_win, key_handler, 0);
    if (mlx_win)
	   mlx_loop(mlx);
}

int init(void)
{
    
}