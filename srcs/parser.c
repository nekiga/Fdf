/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/05/25 16:21:04 by garibeir         ###   ########.fr       */
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
	int		i;
	int		j;
	char **buff;
	
	i = 0;
	cmap()->map = xmalloc(sizeof(t_point *) * data()->rows);
	while (i < data()->rows)
	{
		j = 0;
		buff = ft_split(lines[i],' ');
		cmap()->map[i] = xmalloc(sizeof(t_point ) * data()->line_length );
		while (buff[j])
		{
			cmap()->map[i][j].z = ft_atoi(buff[j]);
			cmap()->map[i][j].x = j * cmap()->spacing + WIDTH / 2 - data()->line_length;
			cmap()->map[i][j].y = i * cmap()->spacing + HEIGHT / 2 - data()->rows;
			cmap()->map[i][j].color = WHITE;
			//printf("[%i]",cmap()->map[i][j].z);
			j++;
		}
		//printf("\n");
		i++;
	}
//	printf("i: %i\n", i);
}

void	get_point_map(char *file)
{
	char **lines;
	
	lines = get_map(file);
	
 	convert_to_point(lines);
	grid_to_iso();
	
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

/* [400][-77][-554][-1031][-1508][-1985][-2463][-2940][-3417][-3894][-4371]
[1239][761][284][-192][-669][-1146][-1623][-2101][-2578][-3055][-3532]
[2078][1601][1123][646][169][-307][-784][-1261][-1739][-2216][-2693]
[2917][2440][1963][1485][1008][531][54][-422][-899][-1377][-1854]
[3756][3279][2802][2325][1847][1370][893][4pixel_put(x, y, start->color);16][-60][-537][-1015]
[4595][4118][3641][3164][2687][2209][1732][1255][778][301][-175]
[5435][4957][4480][4003][3526][3049][2571][2094][1617][1140][663]
[6274][5797][5319][4842][4365][3888][3411][2933][2456][1979][1502]
[7113][6636][6159][5681][5204][4727][4250][3773][3295][2818][2341] */
