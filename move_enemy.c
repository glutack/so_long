#include "so_long.h"

static void	ft_move_enemy_left(t_program *mlx)
{
	if (mlx->map_done[mlx->y][mlx->x] == 'B')
	{
		if (mlx->map.visited[mlx->y][mlx->x] == 'E')
			mlx->map_done[mlx->y][mlx->x] = 'E';
		else
		{							
			mlx->map_done[mlx->y][mlx->x] = '0';
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img.path, mlx->x * SIZE, mlx->y * SIZE);
		}
		if (mlx->map.visited[mlx->y][mlx->x] == 'C')
			mlx->map_done[mlx->y][mlx->x] = 'C';
		mlx->map_done[mlx->y][mlx->x - 1] = 'B';
	}
}

static void	ft_move_enemy_right(t_program *mlx)
{
	if (mlx->map_done[mlx->y][mlx->x] == 'B')
	{
		mlx->map_done[mlx->y][mlx->x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.path, mlx->x * SIZE, mlx->y * SIZE);
		if (mlx->map.visited[mlx->y][mlx->x] == 'C')
			mlx->map_done[mlx->y][mlx->x] = 'C';
		if (mlx->map.visited[mlx->y][mlx->x] == 'E')
			mlx->map_done[mlx->y][mlx->x] = 'E';
		mlx->map_done[mlx->y][mlx->x + 1] = 'B';
		mlx->x++;
	}
}

static void	ft_change_elap(t_program *mlx)
{
	if (mlx->map.elap == 1)
	{
		mlx->map.elap = 0;
		mlx->map.eptr = mlx->img.paulinol1;
	}
	else
	{
		mlx->map.elap = 1;
		mlx->map.eptr = mlx->img.paulinor1;
	}
}

void	ft_move_enemy(t_program *mlx)
{
	ft_init_var(mlx);
	ft_change_elap(mlx);
	while (mlx->y < mlx->map.winy)
	{
		while (mlx->map_done[mlx->y][mlx->x] != '\0')
		{
			if (mlx->map.elap == 0)
			{
				if (mlx->map_done[mlx->y][mlx->x - 1] != '1'
						&& mlx->map_done[mlx->y][mlx->x - 1] != 'B')
				{
					ft_move_enemy_left(mlx);
				}
			}
			else
			{
				if (mlx->map_done[mlx->y][mlx->x + 1] != '1'
						&& mlx->map_done[mlx->y][mlx->x + 1] != 'B')
					ft_move_enemy_right(mlx);
			}
			mlx->x++;
		}
		if (mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
		{
			mlx->dead = 1;
			ft_draw_end_map(mlx);
		}
		mlx->y++;
		mlx->x = 0;
	}
}
