/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:31 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/16 16:19:48 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	pixel_put(int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data()->line_length + x * (data()->bits_per_pixel / 8);
	dst = data()->addr + offset;
	*(unsigned int*)dst = color;
}

t_plot	calculate_line(t_point *start, t_point *end)
{
	t_plot	line;

	if (end->x >= start->x)
	{
		line.dx = end->x - start->x;
		line.sx = 1;
	}
	else
	{
		line.dx = start->x - end->x;
		line.sx = -1;
	}
	if (end->y >= start->y)
	{
		line.dy = -(end->y - start->y);
		line.sy = 1;
	}
	else
	{
		line.dy = -(start->y - end->y);
		line.sy = -1;
	}
	line.po = line.dx + line.dy;
	return (line);
}

int	plotline2(t_plot *plot, int y, int po2)
{
	if (po2 < plot->dx)
	{
		plot->po += plot->dx;
		y += plot->sy;
	}
	return (y);
}

int	plotline3(t_plot *plot, int x, int po2)
{
	if (po2 > plot->dy)
	{
		plot->po += plot->dy;
		x += plot->sx;
	}
	return (x);
}

void	plotline(t_point *start, t_point *end)
{
	t_plot	plot;
	int		y;
	int		x;
	int		po2;

	x = start->x;
	y = start->y;
	plot = calculate_line(start, end);
	while (1)
	{
		pixel_put(x, y, start->color);
		if (x == end->x && y == end->y)
			break ;
		po2 = 2 * plot.po;
		y = plotline2(&plot, y, po2);
		x = plotline3(&plot, x, po2);
	}
}
