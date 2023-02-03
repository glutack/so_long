#include "so_long.h"

char	ft_check_path(char **map, int y, int x, t_program *mlx)
{
	if ((mlx->won == 1) && (mlx->collected == mlx->to_collect))
		return ('T');
	if (x > mlx->map.winx || y > mlx->map.winy || x < 0 || y < 0)
		return ('F');
	if (mlx->map.visited[y][x] == 'T')
		return ('F');
	if (map[y][x] == '1')
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

static void	ft_draw_p(t_program *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene,
		mlx->x * 80, mlx->y * 80);
	mlx->img.selenepos = 0;
	mlx->map.py = mlx->y;
	mlx->map.px = mlx->x;
}

void	ft_draw_map(t_program *mlx)
{
	while (mlx->map_done[mlx->y][mlx->x] != '\0')
	{
		if (mlx->map_done[mlx->y][mlx->x] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == '0')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'C')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.cptr,
				mlx->x * 80, mlx->y * 80);
		}
		else if (mlx->map_done[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.exit,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'B')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.paulinor1,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'P')
			ft_draw_p(mlx);
		mlx->x++;
	}
}