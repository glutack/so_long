#include "so_long.h"

static void	ft_end_map(t_program *mlx)
{
	ft_init_var(mlx);
	if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->won = 1;
			ft_draw_end_map(mlx);
		}
		else
			mlx->won = 2;
	}
	else if (mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
	{
		mlx->dead = 1;
		ft_draw_end_map(mlx);
	}
}

void	ft_move_up(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py - 1][mlx->map.px] != '1')
	{
		ft_animate_player((mlx->map.py - 1), mlx->map.px, mlx);
		if (mlx->map_done[mlx->map.py - 1][mlx->map.px] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py - 1][mlx->map.px] = '0';
			mlx->map.visited[mlx->map.py - 1][mlx->map.px] = '0';
		}
		mlx->map.py--;
		mlx->moves++;
		ft_update_moves(mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E'
				|| mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
			ft_end_map(mlx);
	}
}

void	ft_move_down(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py + 1][mlx->map.px] != '1')
	{
		ft_animate_player((mlx->map.py + 1), mlx->map.px, mlx);
		if (mlx->map_done[mlx->map.py + 1][mlx->map.px] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py + 1][mlx->map.px] = '0';
			mlx->map.visited[mlx->map.py + 1][mlx->map.px] = '0';
		}
		mlx->map.py++;
		mlx->moves++;
		ft_update_moves(mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E'
				|| mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
			ft_end_map(mlx);
	}
}

void	ft_move_left(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py][mlx->map.px - 1] != '1')
	{
		ft_animate_player(mlx->map.py, (mlx->map.px - 1), mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px - 1] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py][mlx->map.px - 1] = '0';
			mlx->map.visited[mlx->map.py][mlx->map.px - 1] = '0';
		}
		mlx->map.px--;
		mlx->moves++;
		ft_update_moves(mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E'
				|| mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
			ft_end_map(mlx);
	}
}

void	ft_move_right(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py][mlx->map.px + 1] != '1')
	{
		ft_animate_player(mlx->map.py, (mlx->map.px + 1), mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px + 1] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py][mlx->map.px + 1] = '0';
			mlx->map.visited[mlx->map.py][mlx->map.px + 1] = '0';
		}
		mlx->map.px++;
		mlx->moves++;
		ft_update_moves(mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E'
				|| mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
			ft_end_map(mlx);
	}
}

/*void	ft_move_down(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py + 1][mlx->map.px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			ft_init_var(mlx);
			mlx->won = 1;
			ft_draw_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->map.py + 1][mlx->map.px] == '0' ||
		mlx->map_done[mlx->map.py + 1][mlx->map.px] == 'C')
	{
		if (mlx->map_done[mlx->map.py + 1][mlx->map.px] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->map.py + 1][mlx->map.px] = 'P';
		mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		ft_animate_player(mlx->map.py + 1, mlx->map.px, mlx);
		mlx->map.py++;
		mlx->moves++;
		ft_update_moves(mlx);
	}
}*/