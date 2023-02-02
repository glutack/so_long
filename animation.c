#include "so_long.h"

void	ft_animate_player(int y, int x, t_program *mlx)
{
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

void static	ft_enemy_animation(t_program *mlx)
{

}

void static	ft_map_animation(t_program *mlx)
{
	
}

int	ft_animation(void *program)
{
	t_program	*mlx;

	mlx = program;
	if (mlx->player.dead || mlx->end)
		return (1);
	if (mlx->frame == 1999)
	{
		ft_enemy_animation
		ft_map_animation
	}
	mlx->frame++;
	if (mlx->frame == 2000)
		mlx->frame = 0;
	return (0);
}