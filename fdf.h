/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:43 by garibeir          #+#    #+#             */
/*   Updated: 2023/05/25 16:20:41 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   FDF_H
# define   FDF_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "colors.h"
#include <stdbool.h>
#include "keyhandler.h"
#include "./includes/libft/libft.h"
#include "./includes/getnextline/get_next_line.h"
#include "./includes/printf/ft_printf.h"
#include "./includes/minilibx-linux/mlx.h"
#include "./includes/minilibx-linux/mlx_int.h"

#define WIDTH 1920
#define HEIGHT 1080
#define NAME "miguek is gat"


typedef unsigned long long ull;

typedef struct	s_data
 {
	void	*addr;
	void	*mlx;
	char 	*win;
    int     width;
    int     height;
	int		bits_per_pixel;
	int		line_length;
	int		rows;
	int		endian;

}				t_data;

typedef struct s_imge 
{
    void *img;
	void*addr;
	int line_len;
	
    
} t_imge;



typedef struct s_point
{
    int		x;
	int		y;
	int		z;
	int		color;
} t_point;

typedef struct s_plot
{
	int		po;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
}			t_plot;

typedef struct s_map
{
	t_point	**map;
	int		z_max;
	int		z_min;
	int		spacing;
	int		elevation;
	int		offset_x;
	int		offset_y;
}			t_map;

// Drawing functions
void	pixel_put(int x, int y, int color);
void	plot_line(t_point *start, t_point *end);
void	print_grid(void);
void	renderer(char *file);
void	grid_to_iso(void);
void	print_grid(void);
//Math functions


//Call structs
t_data   *data(void);
t_imge 	*cimg(void);
t_point     *cpoint(void);
t_map	*cmap(void);

// Auxiliary functions
void	*xmalloc(size_t size);
void init();
void	img_init(void);
void error(char *s, bool allo);
void	cal_line_length(char **lines);
void print_map(void);

//Parser functions
char **get_map(char *file);
void convert_to_point(char **lines);
void	get_point_map(char *file);
int	limits(void);
char **remove_spaces(char **lines);

#endif
