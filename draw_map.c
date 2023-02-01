#include "so_long.h"

void	ft_draw_p(char **map)

void	ft_draw_map(char **map, int y, t_program *mlx)
{
	while ((mlx->y) < y)
	{
		while (map[mlx->y][mlx->x] != '\0')
		{
			if (map[mlx->y][mlx->x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall,
					mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path,
					mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.object,
					mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.exit,
					mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'B')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.paulinor1,
					mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene,
					mlx->x * 80, mlx->y * 80);
				mlx->img.selenepos = 0;
				mlx->map.py = mlx->y;
				mlx->map.px = mlx->x;
			}
			mlx->x++;
		}
		mlx->y++;
		mlx->x = 0;
	}
}

void	ft_redraw_map(int y, int x, t_program *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path,
		mlx->map.px * 80, mlx->map.py * 80);
	if (mlx->img.selenepos == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selener,
			x * 80, y * 80);
		mlx->img.selenepos = 0;
	}
	else if (mlx->img.selenepos == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selenel,
			x * 80, y * 80);
		mlx->img.selenepos = 1;
	}
}