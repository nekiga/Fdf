/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structcall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:20 by garibeir          #+#    #+#             */
/*   Updated: 2023/06/11 18:47:39 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #include "../fdf.h"

t_data *data(void)
{
    static t_data data;

    return (&data);
}

t_imge *cimg(void)
{
    static t_imge img;

    return (&img);
}

t_point *cpoint(void)
{
    static t_point point;
    return (&point);
}

t_map	*cmap(void)
{
	static t_map	map;

	return (&map);
}
