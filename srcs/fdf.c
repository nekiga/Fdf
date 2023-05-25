/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:10 by garibeir          #+#    #+#             */
/*   Updated: 2023/05/25 16:57:03 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"


int main(int ac, char **av)
{
	
    if (ac == 1)
		exit(1);
    init();
	img_init();
	renderer(av[1]);
	mlx_put_image_to_window(data()->mlx, data()->win, cimg()->img, 0, 0);
	key_handler(mlx_key_hook(data()->win, &key_handler, data()));
	// need to understand how the key handler works 
	mlx_loop(data()->mlx);
}

void init(void)
{
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, WIDTH, HEIGHT, NAME);
	cmap()->elevation = 1;
	cmap()->spacing = 20;
	cmap()->offset_x = 500;
	cmap()->offset_y = 400;
	
}
