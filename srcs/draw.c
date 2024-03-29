/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:31 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 15:21:03 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	pixel_put(int x, int y, int color)
{
	char	*dst;

	if (0 <= x && x <= WIDTH && 0 <= y && y <= HEIGHT)
	{
		dst = cimg()->addr + y * cimg()->line_len + x * (data()->bits_per_pixel
				/ 8);
		*(unsigned int *)dst = color;
	}
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

int	plot_line2(t_plot *plot, int y, int po2)
{
	if (po2 < plot->dx)
	{
		plot->po += plot->dx;
		y += plot->sy;
	}
	return (y);
}

int	plot_line3(t_plot *plot, int x, int po2)
{
	if (po2 > plot->dy)
	{
		plot->po += plot->dy;
		x += plot->sx;
	}
	return (x);
}

void	plot_line(t_point *start, t_point *end)
{
	t_plot	plot;
	int		y;
	int		x;
	int		po2;

	x = start->x;
	y = start->y;
	if (start->x < 1 || start->y < 1)
		return ;
	if (end->x < 1 || end->y < 1)
		return ;
	plot = calculate_line(start, end);
	while (1)
	{
		pixel_put(x, y, start->color);
		if (x == end->x && y == end->y)
			break ;
		po2 = 2 * plot.po;
		y = plot_line2(&plot, y, po2);
		x = plot_line3(&plot, x, po2);
	}
}
