#ifndef   FDF_H
# define   FDF_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "colors.h"
#include "keyhandler.h"
#include "./includes/libft/libft.h"
#include "./includes/printf/ft_printf.h"
#include "./includes/minilibx-linux/mlx.h"
#include "./includes/minilibx-linux/mlx_int.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct	s_win
 {
	char	*addr;
    int     width;
    int     height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_win;

typedef struct s_img 
{
    void *img;

    
} t_img;

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
t_win    *cwin(void);
t_img       *cimg(void);
t_point     *cpoint(void);

#endif
