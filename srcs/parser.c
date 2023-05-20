/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/05/20 14:41:09 by garibeir         ###   ########.fr       */
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
	ull temp;
	
	if (!(fd = open(file, 'r')))
		error("Could not open file", false);
	i = 0;
	data()->line_length = 0;
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
	cal_line_length(lines);
	
	return (lines);
	 
}
// Parse that file girl!! u slay xx 
// Turns the array of chars into an array of structs

void convert_to_point(char **lines)
{
	int		i;
	int		j;
	char **buff;
	
	i = 0;
	buff = xmalloc(sizeof(char) * data()->line_length);
	cmap()->map = xmalloc(sizeof(t_point *) * data()->rows);
	while (i < data()->rows)
	{
		j = 0;
		buff = ft_split(lines[i],' ');
		while (j < data()->line_length )
		{
			cmap()->map[i] = xmalloc(sizeof(t_point ) * data()->line_length);
			cmap()->map[i][j].z = ft_atoi(buff[i]);
			cmap()->map[i][j].x = i;// * cmap()->spacing )+ WIDTH / 2 - data()->line_length;
			cmap()->map[i][j].y = j;// * cmap()->spacing )+ HEIGHT / 2 - data()->rows;
			cmap()->map[i][j].color = GREEN;
			printf("z %i x %i y %i\n",cmap()->map[i][j].z, cmap()->map[i][j].x ,cmap()->map[i][j].y );
			j++;
		}
		
		i++;
	}
}

void	get_point_map(char *file)
{
	char **lines;
	
	lines = remove_spaces(get_map(file));
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
	data()->line_length = fcount;
}

char **remove_spaces(char **lines)
{
	char **nlines;
	int	i;
	int	j;
	int	k;

	i = 0;
	nlines = xmalloc(sizeof(char *) * data()->rows + 1);
	while (i < data()->rows) // problem is probably here
	{	
		j = 0;
		k = 0;
		nlines[i] = xmalloc(sizeof(char ) * data()->line_length);
		while(j < data()->line_length * 2 )
		{
			if(lines[i][j] != ' ')
			{
				nlines[i][k] = lines[i][j];
				printf("[%c]", nlines[i][k]); // not saVING THE LAST ONE
				k++;
			}
			j++; 
		}
			printf("\n");
		i++;
	}
	return (nlines);
}

// need to change to a 3d array 
