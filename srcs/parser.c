/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:50:05 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/22 17:47:33 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// opens map and makes the lines
char **get_map(char *file)
{
	char **lines;
	char c[1];
	int	fd;
	ull newlines;
	ull i;
	
	if (!(fd = open(file, 'r')))
		error("Could not open file", false);
	i = 0;
	newlines = 0;
	c[0] = '1';
	while (read(fd, &c, 1)) // counts how many rows
		if (c[0] == '\n')
			newlines++;
	lines = xmalloc(sizeof(char *) * newlines); // allocates amount of rows
	close(fd);
	if (!(fd = open(file, 'r')))
		error("Could not open file", false);
	while (newlines--) // reads file and saves each row 
		lines[i++] = get_next_line(fd);
	return (lines);
	
}
// Parse that file girl!! u slay xx 



//