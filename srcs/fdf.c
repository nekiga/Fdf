/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:10 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/23 20:10:45 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"


int main(int ac, char **av)
{
	
    if (ac == 1)
		exit(1);
	get_point_map(av[1]);
    init();
	img_init();
	print_grid(); 
	mlx_put_image_to_window(data()->mlx, data()->win,cimg()->img, 0, 0);
	key_handler(mlx_key_hook(data()->win, &key_handler, data()));
	mlx_loop(data()->mlx);
}

void init(void)
{
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, WIDTH, HEIGHT, NAME);
	cmap()->elevation = 1;
	cmap()->spacing = 20;
	cmap()->offset_x = 500;
	cmap()->offset_x = 400;
	
}

