/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:16 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 16:25:17 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key)
{
	if (key == ESC_KEY)
		destructor();
	if (key == UP)
	{
		cmap()->elevation++;
		renderer();
	}
	if (key == RIGHT && cmap()->spacing + 10 < WIDTH / 3)
	{
		cmap()->spacing += 10;
		renderer();
	}
	if (key == DOWN)
	{
		cmap()->elevation--;
		renderer();
	}
	if (key == LEFT && cmap()->spacing - 10 > 0)
	{
		cmap()->spacing -= 10;
		renderer();
	}
	else
		key_handler_sub(key);
	return (0);
}

int	key_handler_sub(int key)
{
	if (key == KEY_D)
	{
		cmap()->offset_x += 50;
		renderer();
	}
	if (key == KEY_A)
	{
		cmap()->offset_x -= 50;
		renderer();
	}
	if (key == KEY_W)
	{
		cmap()->offset_y += 50;
		renderer();
	}
	if (key == KEY_S)
	{
		cmap()->offset_y -= 50;
		renderer();
	}
	if (key == KEY_SPACE)
	{
		renderer_original();
	}
	return (0);
}
