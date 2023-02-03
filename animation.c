#include "so_long.h"

void	ft_animate_player(int y, int x, t_program *mlx)
{
	if (mlx->won == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.exit,
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

/*void static	ft_enemy_animation(t_program *mlx)
{

}*/

/*void static	ft_animate_map(t_program *mlx)
{
	if (mlx->map.cptr == mlx->img.object)
		mlx->map.cptr = mlx->img.object0;
	else if (mlx->map.cptr == mlx->img.object0)
		mlx->map.cptr = mlx->img.object;
}

int	ft_animation(void *program)
{
	t_program	*mlx;

	mlx = program;
	if (mlx->dead || mlx->won)
		return (1);
	if (mlx->frame == 1999)
	{
		//ft_enemy_animation;
		ft_animate_map(mlx);
	}
	mlx->frame++;
	if (mlx->frame == 20)
		mlx->frame = 0;
	return (0);
}*/