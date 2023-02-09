#include "so_long.h"

void	ft_animate_player(int y, int x, t_program *mlx)
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
	if (mlx->selenepos == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selener,
			x * 80, y * 80);
		mlx->selenepos = 0;
	}
	else if (mlx->selenepos == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selenel,
			x * 80, y * 80);
		mlx->selenepos = 1;
	}
}

void	ft_move_player(int movy, int movx, t_program *mlx)
{
	if (mlx->map_done[mlx->map.py + (movy)][mlx->map.px + (movx)] != '1')
	{
		ft_animate_player((mlx->map.py + (movy)), mlx->map.px + (movx), mlx);
		if (mlx->map_done[mlx->map.py + (movy)][mlx->map.px + (movx)] == 'C')
		{
			mlx->collected++;
			mlx->map_done[mlx->map.py + (movy)][mlx->map.px + (movx)] = '0';
			mlx->map.visited[mlx->map.py + (movy)][mlx->map.px + (movx)] = '0';
		}
		mlx->map.py += (movy);
		mlx->map.px += (movx);
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