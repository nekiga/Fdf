/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/23 20:08:27 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// opens map and makes the lines
char **get_map(char *file)
{
	char **lines;
	char c[1];
	int	fd;
	ull i;
	ull temp;
	
	if (!(fd = open(file, 'r')))
		error("Could not open file", false);
	i = 0;
	data()->rows = 0;
	c[0] = '1';
	while (read(fd, &c, 1)) // counts how many rows
		if (c[0] == '\n')
			data()->rows++;
	temp = data()->rows;
	lines = xmalloc(sizeof(char *) * data()->rows); // allocates amount of rows
	close(fd);
	if (!(fd = open(file, 'r')))
		error("Could not open file", false);
	while (temp--) // reads file and saves each row 
		lines[i++] = get_next_line(fd);
	return (lines);
	
}
// Parse that file girl!! u slay xx 
// Turns the array of chars into an array of structs

t_point **convert_to_point(char **lines)
{
	t_point **map;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	
	map = xmalloc(sizeof(t_point *) * data()->rows);
	i = 0;
	while (i < data()->rows)
	{
		j = 0;
		map[i] = xmalloc(sizeof(t_point ) * data()->line_length);
		while (j < data()->line_length)
		{
			map[i][j].z = ft_atoi(&lines[i][j]);
			map[i][j].x = (int)j;
			map[i][j].y = (int)i;
			map[i][j].color = GREEN;
			j++;
		}
		i++;
	}
	return(map);                                                                                                                                                                                                                                                                                                                                                                                         
}

t_point **get_point_map(char *file)
{
	char **lines;
	t_point **map;
	lines = get_map(file);
	cal_line_length(lines, data()->rows);
	map = convert_to_point(lines);
	return(map);
	
}

void	cal_line_length(char **lines, int rows)
{
	int	i;
	int	j;
	int count;
	int	fcount;
	
	i = 0;
	count = 0;
	fcount = 0;
	
	while(i != rows)
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == ' ')
				count++;
			j++;
		}
		if (i == 0)
			fcount = count;			
		if (count != fcount && i != 0)
			error("Invalid map", true);
		i++;
		count = 0;
	}
	data()->line_length = count + 1;
}