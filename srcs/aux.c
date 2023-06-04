/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:52:13 by garibeir          #+#    #+#             */
/*   Updated: 2023/06/04 13:43:57 by garibeir         ###   ########.fr       */
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

void error(char *s, bool allo)
{
	ft_printf("%s\n", s);
	if (allo == true)
		exit(1);
	return ;
}

/* void print_map(void)
{
	int	x;
	int y;
	x = 0;
	y = 0;
	printf("\n\tX\n");
	while (x < data()->rows)
	{
		y = 0;
		while (y < data()->line_length)
		{
			printf("[%i]", cmap()->map[x][y].x);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\n\tY\n");
	x = 0;
	y = 0;
	while (x < data()->rows)
	{
		y = 0;
		while (y < data()->line_length)
		{
			printf("[%i]", cmap()->map[x][y].y);
			y++;
		}
		printf("\n");
		x++;
	}
	x = 0;
	y = 0;
	printf("\n\tZ\n");
	while (x < data()->rows)
	{
		y = 0;
		while (y < data()->line_length)
		{
			printf("[%i]", cmap()->map[x][y].z);
			y++;
		}
		printf("\n");
		x++;
	}
} */

void destructor(void)
{
	// free maps
	
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
	exit(0);
}

void copy_map(void)
{
	int	i;
	int	j;

	i = 0;
	cmap()->original_map = xmalloc(sizeof(t_point *) * data()->rows);
	while (i < data()->rows)
	{
		j = 0;
		cmap()->original_map[i] = xmalloc(sizeof(t_point ) * data()->line_length);
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

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}