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
	t_point **map;
	t_imge *img;
	
    if (ac == 1)
		exit(1);
	map = get_point_map(av[1]);
    init();
	img	= img_init();
	make_image(map); 
	mlx_put_image_to_window(data()->mlx, data()->win,img->img, 0, 0);
	key_handler(mlx_key_hook(data()->win, &key_handler, data())); 
}

void init(void)
{
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, WIDTH, HEIGHT, NAME);
	key_handler(mlx_key_hook(data()->win, &key_handler, data()));
	mlx_loop(data()->mlx);
}

 void make_image(t_point **map)
{
	ull	j;
	ull	i;
	
	i = 0;
	j = 0;
	while (map[i])
	{
		plot_line(&map[i][j], &map[i][j + 1]);
		i++;
		j++;
	}
}


