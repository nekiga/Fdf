/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/06/02 19:06:05 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// opens map and makes the lines
// need to adapt the code so it can also save the color value of each map 
 char **get_map(char *file)
{
	char **lines;
	char c[1];
	int	fd;
	int i;
	if (!(fd = open(file, O_RDONLY)))
		error("Could not open file", false);
	i = 0;
	c[0] = '1';
	while (read(fd, &c, 1))
		if (c[0] == '\n')
			data()->rows++;
	lines = xmalloc(sizeof(char *) * data()->rows);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		error("Could not open file", false);
	while (i  < data()->rows)
		lines[i++] = get_next_line(fd);
	cal_line_length(lines);
	close(fd);
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
		cmap()->map[i] = xmalloc(sizeof(t_point ) * data()->line_length + 1);
		while (buff[j] && j < data()->line_length)
		{
			cmap()->map[i][j].z = ft_atoi(buff[j]);
			cmap()->map[i][j].x = j * cmap()->spacing + WIDTH / 2 - data()->line_length;
			cmap()->map[i][j].y = i * cmap()->spacing + HEIGHT / 2 - data()->rows;
			get_color(i, j);
			j++;
		}
		i++;
	} 
	free(buff);
}
 void	get_color(int i, int j)
{

	
	if (cmap()->map[i][j].z * cmap()->elevation <= -10)
		cmap()->map[i][j].color = GRAY;
	else if (cmap()->map[i][j].z * cmap()->elevation <= 0)
		cmap()->map[i][j].color = WHITE;
	else if (cmap()->map[i][j].z * cmap()->elevation <= 14)
		cmap()->map[i][j].color = SILVER;
	else if (cmap()->map[i][j].z * cmap()->elevation <= 30)
		cmap()->map[i][j].color = YELLOW;
	else if (cmap()->map[i][j].z * cmap()->elevation  <= 40)
		cmap()->map[i][j].color = ORANGE;
	else if (cmap()->map[i][j].z * cmap()->elevation  <= 70)
		cmap()->map[i][j].color = GREEN;
	else 
		cmap()->map[i][j].color = WHITE;
	//printf("%i\t%i\n", cmap()->map[i][j].z, x);
	//x++;
}
void	get_point_map(char *file)
{
	static char **lines;
	
	if (!cmap()->map)
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
	bool space;
	// need to change cus extra variables no longer checking if count is same ? 
	i = 0;
	count = 0;
	fcount = 0;
	while(i != data()->rows)
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == ' ' && space != true)
			{
				count++;
				space = true;
			}
			if (lines[i][j + 1] != ' ')
				space = false;
			j++;
		}
		if (i == 0)
			fcount = count;			
		i++;
		count = 0;
	}
	//printf("linelen %i\n", fcount);
	data()->line_length = fcount + 1;
}





