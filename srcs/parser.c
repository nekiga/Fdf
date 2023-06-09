/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/06/11 19:03:30 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_map(char *file)
{
	char c[1];
	int	fd;
	int i;
	
	if ((fd = open(file, O_RDONLY)) == -1)
		error("Error opening file\n");
	i = 0;
	c[0] = '1';
	while (read(fd, &c, 1))
		if (c[0] == '\n')
			data()->rows++;
	data()->lines = xmalloc(sizeof(char *) * data()->rows);
	close(fd);
	if ((fd = open(file, O_RDONLY)) == -1)
		error("Error opening file\n");
	while (i  < data()->rows)
		data()->lines[i++] = get_next_line(fd);
	cal_line_length();
	close(fd);
}
// Parse that file girl!! u slay xx 
// Turns the array of chars into an array of structs

void convert_to_point(void)
{
	int		i;
	int		j;
	char **buff;
	
	i = 0;
	cmap()->map = xmalloc(sizeof(t_point *) * data()->rows);
	while (i < data()->rows)
	{
		j = 0;
		buff = ft_split(data()->lines[i], ' ');
		cmap()->map[i] = xmalloc(sizeof(t_point ) * data()->line_length );
		while (buff[j] && j < data()->line_length )
		{
			cmap()->map[i][j].z = ft_atoi(buff[j]);
			cmap()->map[i][j].x = j * cmap()->spacing + WIDTH / 2 - data()->line_length ;
			cmap()->map[i][j].y = i * cmap()->spacing + HEIGHT / 2 - data()->rows;
			get_color(i, j, buff[j]);
			free(buff[j]);
			j++;
		}
		i++;
		free(buff);
	} 
}
 void	get_color(int i, int j, char *buff)
{
	int x;
	int hexvalue;
	int	temp;
	char temp_char;
	
	hexvalue = 0;
	x = 0;
	temp = 0;
	while (x < (int)ft_strlen(buff))
	{
		if (buff[x] == '0' && (buff[x + 1] == 'x' || buff[x + 1] == 'X'))
		{
			x += 2;
			while (x < (int)ft_strlen(buff))
			{
				temp_char = buff[x];
				temp = 0;
				if (ft_isdigit(buff[x]))
					temp = temp_char - '0';
				else if (ft_isalpha(temp_char))
					temp = (temp_char - 'A' + 10) & 0xF;
				else
					break ;
				hexvalue = (hexvalue << 4) | temp;
				x++;
			}
		}
		x++;
	}
	cmap()->map[i][j].color = GREEN;
	if (hexvalue)
		cmap()->map[i][j].color = hexvalue;
}

void	get_point_map(char *file)
{
	bool first;
	
	first = false;
	if (!cmap()->map)
	{
		first = true;
		get_map(file);
	}
 	convert_to_point();
	grid_to_iso();
	if (first == true)
		copy_map();
}

void	cal_line_length(void)
{
	int	i;
	int	j;
	int count;
	int	fcount;
	bool space;
	
	i = 0;
	count = 0;
	fcount = 0;
	while(i != data()->rows)
	{
		j = 0;
		while (data()->lines[i][j])
		{
			if (data()->lines[i][j] == ' ' && space != true)
			{
				count++;
				space = true;
			}
			if (data()->lines[i][j + 1] != ' ')
				space = false;
			j++;
		}
		if (i == 0)
			fcount = count;			
		i++;
		count = 0;
	}
	data()->line_length = fcount;
}