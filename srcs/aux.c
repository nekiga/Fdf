/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:52:13 by garibeir          #+#    #+#             */
/*   Updated: 2023/06/04 18:02:47 by garibeir         ###   ########.fr       */
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

void error(char *s)
{
	ft_printf("%s\n", s);
	destructor();
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

void	free_arr(void **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

bool is_valid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (i <= (int)ft_strlen(av) - 3)
		{
			if (av[i] == '.' && av[i + 1] == 'f' && av[i + 2] == 'd' && av[ i + 3] == 'f' && av[i + 4] == '\0')
				return (true);
		}
		i++;
	}
	return (false);
}

void print_values(void)
{
	int	i;
	int	j;

	i = 0;
	printf("x\n");
	while (i < data()->rows)
	{
		j = 0;
		while (j < data()->line_length)
		{
			printf("[%i!%i]", cmap()->map[i][j].x, cmap()->map[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}/*
	i = 0;
	printf("y\n");
	while (i < data()->rows)
	{
		j = 0;
		while (j < data()->line_length)
		{
			printf("[%i]", cmap()->map[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}*/
	/*i = 0;
	printf("z\n");
	while (i < data()->rows)
	{
		j = 0;
		while (j < data()->line_length)
		{
			printf("[%i]", cmap()->map[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	printf("color\n");
	while (i < data()->rows)
	{
		j = 0;
		while (j < data()->line_length)
		{
			printf("%0x", cmap()->map[i][j].color);
			j++;
		}
		printf("\n");
		i++;
	}*/
}