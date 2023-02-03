#include "so_long.h"

int	ft_close_win(t_program *mlx)
{
	ft_img_eraser(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	free(mlx->map_done);
	exit(0);
	return (0);
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

void	ft_animate_player(int y, int x, t_program *mlx)
{
	if (mlx->won == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.eptr,
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

int	ft_keys(int keycode, void *program)
{
	t_program	*mlx;

	mlx = program;
	if (keycode == 65307 || keycode == 53)
		ft_close_win(mlx);
	if (mlx->won != 1 && mlx->dead != 1)
	{
		if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		{
			if (keycode == 13)
				ft_move_up(program);
			else if (keycode == 0)
				ft_move_left(program);
			else if (keycode == 1)
				ft_move_down(program);
			else if (keycode == 2)
				ft_move_right(program);
		}
		else if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		{
			if (keycode == 119)
				ft_move_up(program);
			else if (keycode == 97)
				ft_move_left(program);
			else if (keycode == 115)
				ft_move_down(program);
			else if (keycode == 100)
				ft_move_right(program);
		}
	}
	return (0);
}
