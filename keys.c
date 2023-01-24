#include "so_long.h"

int	ft_close_win(t_program *mlx)
{
	ft_img_eraser(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	exit(0);
	return (0);
}

int	ft_keys(int keycode, void *program)
{
	t_program	*mlx;

	mlx = program;
	mlx_hook(mlx->win, 17, 0, ft_close_win, &mlx);
	if (keycode == 65307 || keycode == 53)
		ft_close_win(mlx);
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
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
	return (0);
}

