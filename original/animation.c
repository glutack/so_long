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

void static	ft_animate_map(t_program *mlx)
{
	while (mlx->y < mlx->map.winy)
	{
		while (mlx->map_done[mlx->y][mlx->x] != '\0')
		{
			if (mlx->map_done[mlx->y][mlx->x] == 'C')
			{
				if (mlx->map.cptr == mlx->img.object)
					mlx->map.cptr = mlx->img.object70;
				else if (mlx->map.cptr == mlx->img.object70)
					mlx->map.cptr = mlx->img.object40;
				else if (mlx->map.cptr == mlx->img.object40)
					mlx->map.cptr = mlx->img.object0;
				else if (mlx->map.cptr == mlx->img.object0)
					mlx->map.cptr = mlx->img.object;
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.cptr,
					mlx->x * 80, mlx->y * 80);
			}
			mlx->x++;
		}
		mlx->y++;
		mlx->x = 0;
	}
	
}

int	ft_animation(void *program)
{
	t_program	*mlx;

	mlx = program;
	
	if (mlx->dead || mlx->won)
		return (1);
	if (mlx->frame == 2999)
	{
		printf("a");
		//ft_enemy_animation;
		ft_init_var(mlx);
		ft_animate_map(mlx);
	}
	mlx->frame++;
	if (mlx->frame == 3000)
		mlx->frame = 0;
	return (0);
}