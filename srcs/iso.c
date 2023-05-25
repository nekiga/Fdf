#include "../fdf.h"

void	grid_to_iso(void)
{
	int	x;
	int	y;
	int	wx;
	int	wy;

	y = -1;
	while (++y < data()->rows)
	{
		x = -1;
		while (++x < data()->line_length)
		{
			wx = cmap()->map[y][x].x;
			wy = cmap()->map[y][x].y;
			cmap()->map[y][x].x = (wx - wy) * cos(0.523599) + cmap()->offset_x;
			cmap()->map[y][x].y = (wx + wy) * sin(0.523599) - cmap()->offset_y
			- cmap()->map[y][x].z * cmap()->elevation;
		}
	}
	//limits();
}


void	print_grid(void)
{
	 int	x = -1;
	 int	y;

	y = -1;
	while (++y < data()->rows - 1)
	{
		x = -1;
		while (++x < data()->line_length - 1)
		{
			plot_line(&cmap()->map[y][x], &cmap()->map[y][x + 1]);
		 	 plot_line(&cmap()->map[y][x], &cmap()->map[y + 1][x]);
			if (y == 0)
				plot_line(&cmap()->map[data()->rows - 1][x],
					&cmap()->map[data()->rows - 1][x + 1]);
		}
			plot_line(&cmap()->map[y][data()->line_length - 1], &cmap()->map[y
				+ 1][data()->line_length - 1]);  
	}  
	/* while (x < data()->line_length - 1)
	{
		plot_line(&cmap()->map[0][x], &cmap()->map[0][x + 1]);
		x++;
	} */
}

int	limits2(int y, int x)
{
	if (!(0 <= cmap()->map[y][x].x && cmap()->map[y][x].x <= WIDTH))
		return (0);
	if (!(0 <= cmap()->map[y][x].y && cmap()->map[y][x].y <= HEIGHT))
		return (0);
	return (1);
}

int	limits(void)
{
	if (!(limits2(0, 0) && limits2(0, data()->line_length - 1)))
		return (0);
	if (!(limits2(data()->rows - 1, 0) && limits2(data()->rows - 1,
				data()->line_length - 1)))
		return (0);
	return (1);
}