/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:52:13 by garibeir          #+#    #+#             */
/*   Updated: 2023/05/25 16:17:48 by garibeir         ###   ########.fr       */
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
	if (allo)
	{
		
		free(data()->addr);
		free(data()->win); 
		free(data());
	}
	exit(1);
}

void print_map(void)
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
}

