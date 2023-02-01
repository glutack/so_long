#include "so_long.h"

char	ft_path_check(char **map, int y, int x, t_program *mlx)
{
	printf("%i, %i\n", y, x);

	if (x == mlx->map.ex && y == mlx->map.ey)
		return ('T');
	if (x > mlx->map.winx || y > mlx->map.winy)
		return ('F');
	if (x < 0 || y < 0)
		return ('F');
	if (mlx->map.visited[y][x] == 'T')
		return ('F');
	printf("%c", mlx->map.visited[y][x]);
	if (map[y][x] == '1')
		return ('F');
	/*if (map[y][x] == 'C')
		mlx->collected++;*/
	mlx->map.visited[y][x] = 'T';
	if (ft_path_check(map, y, (x + 1), mlx) == 'T')
		return ('T');
	if (ft_path_check(map, y, (x - 1), mlx) == 'T')
		return ('T');
	if (ft_path_check(map, (y + 1), x, mlx) == 'T')
		return ('T');
	if (ft_path_check(map, (y - 1), x, mlx) == 'T')
		return ('T');
	return ('F');
}