/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structcall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:20 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/16 16:12:58 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #include "../fdf.h"

t_win *data(void)
{
    static t_win data;

    return (&data);
}

t_img *cimg(void)
{
    static t_img img;

    return (&img);
}

t_point *cpoint(void)
{
    static t_point point;

    return (&point);
}
