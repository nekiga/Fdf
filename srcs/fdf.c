/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:10 by garibeir          #+#    #+#             */
/*   Updated: 2023/06/02 19:22:55 by garibeir         ###   ########.fr       */
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
	mlx_hook(data()->win, 17, 1L << 2, (void *)destructor, 0);
	mlx_loop(data()->mlx);
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
	mlx_string_put(data()->mlx, data()->win, 100, 100, SLAY, "Commands:");
	mlx_string_put(data()->mlx, data()->win, 100, 120, SLAY, "UP   ARROW:    Increase elevation");
	mlx_string_put(data()->mlx, data()->win, 100, 140, SLAY, "DOWN ARROW:    Decrease elevation");
	mlx_string_put(data()->mlx, data()->win, 100, 160, SLAY, "A ");
}

/*void quit(void)
{
	if
	free()
}*/