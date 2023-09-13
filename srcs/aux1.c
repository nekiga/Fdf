/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:46:22 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:24 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_point_map(char *file)
{
	bool	first;

	first = false;
	if (!cmap()->map)
	{
		first = true;
		data()->lines = get_map(file);
		allocate_map();
	}
	if (data()->line_length > 400)
		cmap()->spacing = 2;
	cmap()->offset_y = (HEIGHT / 3) + data()->rows * 2;
	if (cmap()->offset_y > HEIGHT)
		cmap()->offset_y = HEIGHT / 3;
	convert_to_point();
	grid_to_iso();
	if (first == true)
		copy_map();
}

void	cal_line_length(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 1;
	if (!*str)
		return ;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			words++;
		i++;
	}
	if (str[0] == ' ')
		words--;
	if (str[ft_strlen(str) - 1] == ' ')
		words--;
	data()->line_length = words;
}

bool	is_valid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (i <= (int)ft_strlen(av) - 3)
		{
			if (av[i] == '.' && av[i + 1] == 'f' && av[i + 2] == 'd' && av[i
					+ 3] == 'f' && av[i + 4] == '\0')
				return (true);
		}
		i++;
	}
	return (false);
}

void	limit(void)
{
	if (!limits())
	{
		if (cmap()->spacing > 5)
		{
			cmap()->spacing -= 5;
			get_point_map(data()->file);
		}
		else
		{
			cmap()->elevation = 1;
			cmap()->spacing = 20;
			cmap()->offset_x = 500;
			cmap()->offset_y = 400;
		}
	}
}
