/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:43 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/22 17:12:42 by garibeir         ###   ########.fr       */
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
#define NAME "***************************************"

typedef unsigned long long ull;

typedef struct	s_win
 {
	void	*addr;
	char 	*win;
    int     width;
    int     height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_win;

typedef struct s_imge 
{
    void *img;

    
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

// Drawing functions
void	pixel_put(int x, int y, int color);
int    draw_line(int x0, int x1, int y0, int y1);

//Math functions
float rfPartOfNumber(float x);
float fPartOfNumber(float x);
int roundNumber(float x);
int iPartOfNumber(float x);
float m_abs(float x );
void swap(int* a , int*b);

//Call structs
t_win   *data(void);
t_img       *cimg(void);
t_point     *cpoint(void);

// Auxiliary functions
void	*xmalloc(size_t size);
void init();
void error(char *s, bool allo);

//Parser functions
char **get_map(char *file);

#endif
