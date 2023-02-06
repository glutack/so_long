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

static void	ft_animate_player(int y, int x, t_program *mlx)
{
	if (mlx->won == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.exptr,
			mlx->map.px * 80, mlx->map.py * 80);
		mlx->won = 0;
	}
	else
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

static void	ft_move_done(t_program *mlx)
{
	mlx->moves++;
	ft_putstr_fd("moves -> ", 1);
	ft_putnbr_fd(mlx->moves, 1);
	ft_putstr_fd("\n", 1);
	ft_update_moves(mlx);
	if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E'
			|| mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
		ft_end_map(mlx);
}

void	ft_move_updown(int mov, t_program *mlx)
{
	if (mlx->map_done[mlx->map.py + (mov)][mlx->map.px] != '1')
	{
		ft_animate_player((mlx->map.py + (mov)), mlx->map.px, mlx);
		if (mlx->map_done[mlx->map.py + (mov)][mlx->map.px] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py + (mov)][mlx->map.px] = '0';
			mlx->map.visited[mlx->map.py + (mov)][mlx->map.px] = '0';
		}
		mlx->map.py += (mov);
		ft_move_done(mlx);
	}
}

void	ft_move_leftright(int mov, t_program *mlx)
{
	if (mlx->map_done[mlx->map.py][mlx->map.px + (mov)] != '1')
	{
		ft_animate_player(mlx->map.py, (mlx->map.px + (mov)), mlx);
		if (mlx->map_done[mlx->map.py][mlx->map.px + (mov)] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py][mlx->map.px + (mov)] = '0';
			mlx->map.visited[mlx->map.py][mlx->map.px + (mov)] = '0';
		}
		mlx->map.px += (mov);
		ft_move_done(mlx);
	}
}
