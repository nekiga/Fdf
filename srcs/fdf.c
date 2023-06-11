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

//slay xx
// still has memory leaks
// need to do function to check values of the map
// t1 and t2 are going gayzy
// check if hex valuesa re not messing with other values
// getting negative y values on t1
int main(int ac, char **av)
{
	
    if (ac != 2)
		error("Invalid arguments.\nUsage: ./fdf *.fdf\n");
	if (!is_valid(av[1]))
		error("Invalid arguments.\nUsage: ./fdf *.fdf\n");
	data()->file = av[1];
    init();
	img_init();
	renderer();
	mlx_key_hook(data()->win, &key_handler, data());
	mlx_hook(data()->win, EVENT_CLOSE_BTN, 1L << 2, (void *)destructor, 0);
	mlx_loop(data()->mlx);
	//destructor();
}

void init(void)
{
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, WIDTH, HEIGHT, NAME);
	data()->line_length = 0;
	data()->rows = 0;
	cmap()->elevation = 1;
	cmap()->spacing = 20;
	cmap()->offset_x = 500;
	cmap()->offset_y = 400;
	
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
