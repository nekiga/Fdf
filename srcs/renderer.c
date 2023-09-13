/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:43:42 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 15:20:47 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_init(void)
{
	if (cmap()->map)
	{
		mlx_destroy_image(data()->mlx, cimg()->img);
		mlx_clear_window(data()->mlx, data()->win);
	}
	(cimg()->img) = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
	(cimg()->addr) = mlx_get_data_addr(cimg()->img, &data()->bits_per_pixel,
			&cimg()->line_len, &data()->endian);
}

void	renderer(void)
{
	get_point_map(data()->file);
	img_init();
	print_map();
	mlx_put_image_to_window(data()->mlx, data()->win, cimg()->img, 0, 0);
	menu();
}

void	renderer_original(void)
{
	img_init();
	print_original_map();
	mlx_put_image_to_window(data()->mlx, data()->win, cimg()->img, 0, 0);
	menu();
}
