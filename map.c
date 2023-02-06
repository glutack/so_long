#include "so_long.h"

char	ft_check_path(char **map, int y, int x, t_program *mlx)
{
	if ((mlx->won == 1) && (mlx->collected == mlx->to_collect))
		return ('T');
	if (x > mlx->map.winx || y > mlx->map.winy || x < 0 || y < 0)
		return ('F');
	if (mlx->map.visited[y][x] == 'T')
		return ('F');
	if (map[y][x] == '1' || map[y][x] == 'B')
		return ('F');
	if (map[y][x] == 'C')
		mlx->collected++;
	if (map[y][x] == 'E')
		mlx->won++;
	mlx->map.visited[y][x] = 'T';
	if (ft_check_path(map, y, (x + 1), mlx) == 'T')
		return ('T');
	if (ft_check_path(map, y, (x - 1), mlx) == 'T')
		return ('T');
	if (ft_check_path(map, (y + 1), x, mlx) == 'T')
		return ('T');
	if (ft_check_path(map, (y - 1), x, mlx) == 'T')
		return ('T');
	return ('F');
}

void	ft_draw_p(t_program *mlx)
{
	if (mlx->img.selenepos == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selener,
			mlx->map.px * SIZE, mlx->map.py * SIZE);
		mlx->img.selenepos = 0;
	}
	else if (mlx->img.selenepos == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selenel,
			mlx->map.px * SIZE, mlx->map.py * SIZE);
		mlx->img.selenepos = 1;
	}
}

void	ft_draw_map(t_program *mlx)
{
	while (mlx->map_done[mlx->y][mlx->x] != '\0')
	{
		if (mlx->map_done[mlx->y][mlx->x] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall,
				mlx->x * SIZE, mlx->y * SIZE);
		else if (mlx->y == mlx->map.py && mlx->x == mlx->map.px)
			ft_draw_p(mlx);
		else if ((mlx->map_done[mlx->y][mlx->x] == '0'
			|| mlx->map_done[mlx->y][mlx->x] == 'P'))
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path,
				mlx->x * SIZE, mlx->y * SIZE);
		else if (mlx->map_done[mlx->y][mlx->x] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.cptr,
				mlx->x * SIZE, mlx->y * SIZE);
		else if (mlx->map_done[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.exptr,
				mlx->x * SIZE, mlx->y * SIZE);
		else if (mlx->map_done[mlx->y][mlx->x] == 'B')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.eptr,
				mlx->x * SIZE, mlx->y * SIZE);
		ft_update_moves(mlx);
		mlx->x++;
	}
}

void	ft_draw_end_map(t_program *mlx)
{
	ft_init_var(mlx);
	mlx->x = 1;
	while (mlx->y < mlx->map.winy)
	{
		while (mlx->map_done[mlx->y][mlx->x] != '\0')
		{
			if (mlx->dead == 1)
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.paulinol1,
					mlx->x * SIZE, mlx->y * SIZE);
			else if (mlx->won == 1)
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.moves,
					mlx->x * SIZE, mlx->y * SIZE);
			mlx->x++;
		}
		mlx->y++;
		mlx->x = 0;
	}
}
