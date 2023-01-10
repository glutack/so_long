#include "so_long.h"

int	ft_close_win(void *program)
{
	t_program	*mlx;

	mlx = program;
	ft_img_eraser(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	exit(0);
	return (0);
}

int	ft_keys(int keycode, void *program)
{
	//t_program	*mlx;
	
	//mlx = program;
	printf("%d", keycode);
	if (keycode == 65307)
		ft_close_win(program);
	return (0);
}