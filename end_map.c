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

static void	ft_draw_end_msg(t_program *mlx)
{
	if (mlx->y == (mlx->map.winy / 2)
		&& mlx->x == (mlx->map.winx / 2) - 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.you,
			mlx->x * 80, mlx->y * 80);
	else if (mlx->y == (mlx->map.winy / 2) && mlx->x == (mlx->map.winx / 2))
	{
		if (mlx->dead == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.paulinol1,
				mlx->x * 80, mlx->y * 80);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene,
				mlx->x * 80, mlx->y * 80);
	}
	else if (mlx->y == (mlx->map.winy / 2) && mlx->x == (mlx->map.winx / 2) + 1)
	{
		if (mlx->dead == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.lose,
				mlx->x * 80, mlx->y * 80);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.win,
				mlx->x * 80, mlx->y * 80);
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall,
			mlx->x * 80, mlx->y * 80);
}

void	ft_draw_end_map(t_program *mlx)
{
	ft_init_var(mlx);
	mlx->x = 1;
	while (mlx->y < mlx->map.winy)
	{
		while (mlx->map_done[mlx->y][mlx->x] != '\0')
		{
			ft_draw_end_msg(mlx);
			mlx->x++;
		}
		mlx->y++;
		mlx->x = 0;
	}
}
