#include "so_long.h"

char	ft_check_path(char **map, int y, int x, t_program *mlx)
{
	if ((mlx->end == 1) && (mlx->collected == mlx->to_collect))
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
		mlx->end++;
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