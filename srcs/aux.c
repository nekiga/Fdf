/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:52:13 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 16:24:53 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	*xmalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		exit(1);
	ft_bzero(result, size);
	return (result);
}

void	error(char *s)
{
	ft_printf("%s\n", s);
	destructor();
}

void	destructor(void)
{
	if (cimg()->img)
		mlx_destroy_image(data()->mlx, cimg()->img);
	if (data()->win)
		mlx_destroy_window(data()->mlx, data()->win);
	if (data()->mlx)
		mlx_loop_end(data()->mlx);
	if (data()->mlx)
	{
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	if (cmap()->map)
		free_arr((void **)cmap()->map, data()->rows);
	if (cmap()->original_map)
		free_arr((void **)cmap()->original_map, data()->rows);
	if (data()->lines)
		free_arr((void **)data()->lines, data()->rows);
	exit(0);
}

void	copy_map(void)
{
	int	i;
	int	j;

	i = 0;
	cmap()->original_map = xmalloc(sizeof(t_point *) * data()->rows);
	while (i < data()->rows)
	{
		j = 0;
		cmap()->original_map[i] = xmalloc(sizeof(t_point)
			* data()->line_length);
		while (j < data()->line_length)
		{
			cmap()->original_map[i][j].x = cmap()->map[i][j].x;
			cmap()->original_map[i][j].y = cmap()->map[i][j].y;
			cmap()->original_map[i][j].z = cmap()->map[i][j].z;
			cmap()->original_map[i][j].color = cmap()->map[i][j].color;
			j++;
		}
		i++;
	}
}

void	free_arr(void **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}
