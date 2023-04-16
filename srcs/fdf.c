/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:10 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/16 16:46:25 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

int main(void)
{
    
    init();
	key_handler(mlx_key_hook(data()->win, &key_handler, data()));
}

void init(void)
{
	data()->addr = mlx_init();
	data()->win = mlx_new_window(data()->addr, WIDTH, HEIGHT, NAME);
	key_handler(mlx_key_hook(data()->win, &key_handler, data()));
	mlx_loop(data()->addr);
    
}

