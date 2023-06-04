/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:10 by garibeir          #+#    #+#             */
/*   Updated: 2023/06/04 17:57:27 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

//read colors
// make destructor actually do things other then just exit
// make proteciton for valid map
//slay xx
int main(int ac, char **av)
{
	
    if (ac == 1)
		exit(1);
	data()->file = av[1];
    init();
	img_init();
	renderer();
	
	mlx_key_hook(data()->win, &key_handler, data());
	mlx_hook(data()->win, EVENT_CLOSE_BTN, 1L << 2, (void *)destructor, 0);
	mlx_loop(data()->mlx);
}

void init(void)
{
	
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, WIDTH, HEIGHT, NAME);
<<<<<<< HEAD
	cmap()->elevation = 2;
=======
	data()->line_length = 0;
	data()->rows = 0;
	cmap()->elevation = 1;
>>>>>>> f633b7dc8cf2c45fe056b97d5fedae8ada725d5d
	cmap()->spacing = 20;
	cmap()->offset_x = (WIDTH / 2) - 100;
	cmap()->offset_y = (HEIGHT / 2) - 100;
	
}

void menu(void)
{
	mlx_string_put(data()->mlx, data()->win, 100, 100, RED, "Commands:");
	mlx_string_put(data()->mlx, data()->win, 100, 120, SLAY, "UP   ARROW:        Increase elevation");
	mlx_string_put(data()->mlx, data()->win, 100, 140, SLAY, "DOWN ARROW:        Decrease elevation");
	mlx_string_put(data()->mlx, data()->win, 100, 160, SLAY, "W      KEY:        Move up");
	mlx_string_put(data()->mlx, data()->win, 100, 180, SLAY, "A      KEY:        Move to the left");
	mlx_string_put(data()->mlx, data()->win, 100, 200, SLAY, "S      KEY:        Move down");
	mlx_string_put(data()->mlx, data()->win, 100, 220, SLAY, "D      KEY:        Move to the right");
	mlx_string_put(data()->mlx, data()->win, 100, 240, SLAY, "SPACE  BAR:        Show original");
}
