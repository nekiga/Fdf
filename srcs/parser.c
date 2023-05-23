/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/05/23 18:15:08 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// opens map and makes the lines



 char **get_map(char *file)
{
	char **lines;
	char c[1];
	int	fd;
	int i;
	
	if (!(fd = open(file, O_RDONLY)))
		error("Could not open file", false);
	i = 0;
	data()->line_length = 0;
	data()->rows = 0;
	c[0] = '1';
	while (read(fd, &c, 1)) // counts how many rows
		if (c[0] == '\n')
			data()->rows++;
	lines = xmalloc(sizeof(char *) * data()->rows); // allocates amount of rows
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		error("Could not open file", false);
	while (i  < data()->rows)
	{
		lines[i] = get_next_line(fd); // reads file and saves each row 
		i++;	
	}
	cal_line_length(lines);
	
	return (lines);
	 
}
// Parse that file girl!! u slay xx 
// Turns the array of chars into an array of structs

void convert_to_point(char **lines)
{
    int i;
    int j;
    char **buff;
    
    i = 0;
    cmap()->map = xmalloc(sizeof(t_point *) * data()->rows);
    while (i < data()->rows)
    {
        j = 0;
        buff = ft_split(lines[i], ' ');
        while (buff[j]) 
        {
            cmap()->map[i] = xmalloc(sizeof(t_point) * data()->line_length);
            cmap()->map[i][j].z = ft_atoi(buff[j]);
            cmap()->map[i][j].x = i * cmap()->spacing + WIDTH / 2 - data()->line_length;
            cmap()->map[i][j].y = j * cmap()->spacing + HEIGHT / 2 - data()->rows;
            cmap()->map[i][j].color = GREEN;
            j++;
        }
        i++;
    }
}

void	get_point_map(char *file)
{
	char **lines;
	
	lines = get_map(file);
	
 	convert_to_point(lines);
	
}

void	cal_line_length(char **lines)
{
	int	i;
	int	j;
	int count;
	int	fcount;
	
	i = 0;
	count = 0;
	fcount = 0;
	
	while(i != data()->rows)
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
	data()->line_length = fcount + 1;
}



// need to change to a 3d array 
