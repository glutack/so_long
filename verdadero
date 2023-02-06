#include "so_long.h"

void	ft_end_map(t_program *mlx)
{
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
		ft_putstr_fd("moves -> ", 1);
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
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
		ft_putstr_fd("moves -> ", 1);
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
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
		ft_putstr_fd("moves -> ", 1);
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
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
		ft_putstr_fd("moves -> ", 1);
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
		ft_update_moves(mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E'
				|| mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
			ft_end_map(mlx);
	}
}
