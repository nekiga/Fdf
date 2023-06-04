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
	limit();
}


void	print_map(void)
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

}

void	print_original_map(void)
{
	 int	x = -1;
	 int	y;

	y = -1;
	while (++y < data()->rows - 1)
	{
		x = -1;
		while (++x < data()->line_length - 1)
		{
			plot_line(&cmap()->original_map[y][x], &cmap()->original_map[y][x + 1]);
		 	plot_line(&cmap()->original_map[y][x], &cmap()->original_map[y + 1][x]);
			if (y == 0)
				plot_line(&cmap()->original_map[data()->rows - 1][x],
					&cmap()->original_map[data()->rows - 1][x + 1]);
		}
			plot_line(&cmap()->original_map[y][data()->line_length - 1], &cmap()->original_map[y
				+ 1][data()->line_length - 1]);  
	}  

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

void	limit(void)
{
	if (!limits())
	{
		if (cmap()->spacing > 5)
		{
			cmap()->spacing -= 5;
			get_point_map(data()->file);
		}
		else
		{
			cmap()->elevation = 1;
			cmap()->spacing = 20;
			cmap()->offset_x = 500;
			cmap()->offset_y = 400;
		}
	}
}