/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 16:25:06 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	**get_map(char *file)
{
	char	**lines;
	char	c[1];
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error opening file\n");
	i = 0;
	c[0] = '1';
	while (read(fd, &c, 1))
		if (c[0] == '\n')
			data()->rows++;
	if (!data()->rows)
		destructor();
	lines = xmalloc(sizeof(char *) * data()->rows);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error opening file\n");
	while (i < data()->rows)
		lines[i++] = get_next_line(fd);
	cal_line_length(lines[0]);
	close(fd);
	return (lines);
}
// Turns the array of chars into an array of structs

void	convert_to_point(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < data()->rows)
	{
		j = 0;
		(data()->buff) = ft_split(data()->lines[i], ' ');
		while (data()->buff[j] && j < data()->line_length)
		{
			cmap()->map[i][j].z = ft_atoi(data()->buff[j]);
			cmap()->map[i][j].x = j * cmap()->spacing + WIDTH / 2
			-data()->line_length;
			cmap()->map[i][j].y = i * cmap()->spacing + HEIGHT / 2
			- data()->rows;
			get_color(i, j, data()->buff[j]);
			free(data()->buff[j]);
			j++;
		}
		free(data()->buff[j]);
		free(data()->buff);
		i++;
	}
}

void	allocate_map(void)
{
	int	i;

	i = 0;
	cmap()->map = xmalloc(sizeof(t_point *) * data()->rows);
	while (i < data()->rows)
		cmap()->map[i++] = xmalloc(sizeof(t_point) * data()->line_length);
}

void	get_color_sub(int x, int *hexvalue, char *buff)
{
	int		temp;
	char	temp_char;

	temp = 0;
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
		*hexvalue = (*hexvalue << 4) | temp;
		x++;
	}
}

void	get_color(int i, int j, char *buff)
{
	int		x;
	int		hexvalue;

	hexvalue = 0;
	x = 0;
	while (x < (int)ft_strlen(buff))
	{
		if (buff[x] == '0' && (buff[x + 1] == 'x' || buff[x + 1] == 'X'))
		{
			x += 2;
			get_color_sub(x, &hexvalue, buff);
		}
		x++;
	}
	cmap()->map[i][j].color = GREEN;
	if (hexvalue)
		cmap()->map[i][j].color = hexvalue;
}
