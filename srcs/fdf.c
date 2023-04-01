/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:10 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/01 17:19:46 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

int main(void)
{
    t_win *data;
    
    init (data);
    mlx_loop(data->addr);
    

    
}

void init(t_win *data)
{
	data = xmalloc(sizeof(t_win));
	data->addr = mlx_init();
	data->win = mlx_new_window(data->addr, WIDTH, HEIGHT, NAME);
   
    
}
