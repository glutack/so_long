#include "so_long.h"

char	ft_check_path(char **map, int y, int x, t_program *mlx)
{
	if ((mlx->won == 1) && (mlx->collected == mlx->to_collect))
		return ('T');
	if ((x > mlx->map.winx || y > mlx->map.winy || x < 0 || y < 0)
		|| mlx->map.visited[y][x] == 'T' || map[y][x] == '1')
		return ('F');
	if (map[y][x] == 'C')
		mlx->collected++;
	if (map[y][x] == 'E')
		mlx->won++;
	mlx->map.visited[y][x] = 'T';
	if (ft_check_path(map, y, (x + 1), mlx) == 'T'
		|| ft_check_path(map, y, (x - 1), mlx) == 'T'
		|| ft_check_path(map, (y + 1), x, mlx) == 'T'
		|| ft_check_path(map, (y - 1), x, mlx) == 'T')
		return ('T');
	return ('F');
}

void	ft_draw_map(t_program *mlx)
{
	while (mlx->map_done[mlx->y][mlx->x] != '\0')
	{
		if (mlx->map_done[mlx->y][mlx->x] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->y == mlx->map.py && mlx->x == mlx->map.px)
			ft_animate_player(mlx->y, mlx->x, mlx);
		else if ((mlx->map_done[mlx->y][mlx->x] == '0'
			|| mlx->map_done[mlx->y][mlx->x] == 'P'))
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.cptr,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'B')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.eptr,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.exptr,
				mlx->x * 80, mlx->y * 80);
		ft_update_moves(mlx);
		mlx->x++;
	}
}