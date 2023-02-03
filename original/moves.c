#include "so_long.h"

void	ft_move_up(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py - 1][mlx->map.px] != '1')
	{
		ft_animate_player((mlx->map.py - 1), mlx->map.px, mlx);
		if (mlx->map_done[mlx->map.py - 1][mlx->map.px] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py - 1][mlx->map.px] = '0';
		}
		if (mlx->map_done[mlx->map.py - 1][mlx->map.px] == 'E')
		{
			if (mlx->collected == mlx->to_collect)
			{
				mlx->won = 1;
				ft_end_map(mlx);
			}
			else
				mlx->won = 2;
		}
		mlx->map.py--;
		mlx->moves++;
		ft_update_moves(mlx);
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
			mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		}
		if (mlx->map_done[mlx->map.py + 1][mlx->map.px] == 'E')
		{
			if (mlx->collected == mlx->to_collect)
			{
				mlx->won = 1;
				ft_end_map(mlx);
			}
			else
				mlx->won = 2;
		}
		mlx->map.py++;
		mlx->moves++;
		ft_update_moves(mlx);
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
			mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		}
		if (mlx->map_done[mlx->map.py][mlx->map.px - 1] == 'E')
		{
			if (mlx->collected == mlx->to_collect)
			{
				mlx->won = 1;
				ft_end_map(mlx);
			}
			else
				mlx->won = 2;
		}
		mlx->map.px--;
		mlx->moves++;
		ft_update_moves(mlx);
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
			mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		}
		mlx->map.px++;
		mlx->moves++;
		ft_update_moves(mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E')
		{
			if (mlx->collected == mlx->to_collect)
			{
				ft_init_var(mlx);
				mlx->won = 1;
				ft_end_map(mlx);
			}
			else
				mlx->won = 2;
		}
	}
}

void	ft_update_moves(t_program *mlx)
{
	char	*moves;

	moves = ft_itoa(mlx->moves);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.moves,
		0 * 80, 0 * 80);
	mlx_string_put(mlx->mlx, mlx->win, 25, 35, 000000, "moves");
	mlx_string_put(mlx->mlx, mlx->win, 38, 50, 000000, ft_itoa(mlx->moves));
	free(moves);
}

/*void	ft_move_down(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py + 1][mlx->map.px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			ft_init_var(mlx);
			mlx->won = 1;
			ft_end_map(mlx);
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