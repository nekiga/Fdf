/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structcall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:20 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/01 16:47:22 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_win *cwin(void)
{
    static t_win *win;

    return (&win);
}

t_img *cimg(void)
{
    static t_img *img;

    return (&img);
}

t_point *cpoint(void)
{
    static t_point *point;

    return (&point);
}

