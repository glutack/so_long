#include "so_long.h"

static void	ft_animate_obj(t_program *mlx)
{
	if (mlx->map.clap == 0)
	{
		if (mlx->map.cptr == mlx->img.object)
			mlx->map.cptr = mlx->img.object70;
		else if (mlx->map.cptr == mlx->img.object70)
			mlx->map.cptr = mlx->img.object40;
		else if (mlx->map.cptr == mlx->img.object40)
			mlx->map.cptr = mlx->img.object0;
		else if (mlx->map.cptr == mlx->img.object0)
			mlx->map.clap++;
	}
	else if (mlx->map.clap == 1)
	{
		if (mlx->map.cptr == mlx->img.object0)
			mlx->map.cptr = mlx->img.object40;
		else if (mlx->map.cptr == mlx->img.object40)
			mlx->map.cptr = mlx->img.object70;
		else if (mlx->map.cptr == mlx->img.object70)
			mlx->map.cptr = mlx->img.object;
		else if (mlx->map.cptr == mlx->img.object)
			mlx->map.clap--;
	}
}

static void	ft_animate_exit(t_program *mlx)
{
	if (mlx->map.exlap == 0)
	{
		if (mlx->map.exptr == mlx->img.exit0)
			mlx->map.exptr = mlx->img.exit40;
		else if (mlx->map.exptr == mlx->img.exit40)
			mlx->map.exptr = mlx->img.exit70;
		else if (mlx->map.exptr == mlx->img.exit70)
			mlx->map.exptr = mlx->img.exit;
		else if (mlx->map.exptr == mlx->img.exit)
			mlx->map.exlap++;
	}
	else if (mlx->map.exlap == 1)
	{
		if (mlx->map.exptr == mlx->img.exit)
			mlx->map.exptr = mlx->img.exit70;
		else if (mlx->map.exptr == mlx->img.exit70)
			mlx->map.exptr = mlx->img.exit40;
		else if (mlx->map.exptr == mlx->img.exit40)
			mlx->map.exptr = mlx->img.exit0;
		else if (mlx->map.exptr == mlx->img.exit0)
			mlx->map.exlap--;
	}
}

static void	ft_animate_enemy(t_program *mlx)
{
	if (mlx->map.elap == 0)
	{
		if (mlx->map.eptr == mlx->img.paulinol1)
			mlx->map.eptr = mlx->img.paulinol2;
		else if (mlx->map.eptr == mlx->img.paulinol2)
			mlx->map.eptr = mlx->img.paulinol3;
		else if (mlx->map.eptr == mlx->img.paulinol3)
			mlx->map.eptr = mlx->img.paulinol1;
	}
	else if (mlx->map.elap == 1)
	{
		if (mlx->map.eptr == mlx->img.paulinor1)
			mlx->map.eptr = mlx->img.paulinor2;
		else if (mlx->map.eptr == mlx->img.paulinor2)
			mlx->map.eptr = mlx->img.paulinor3;
		else if (mlx->map.eptr == mlx->img.paulinor3)
			mlx->map.eptr = mlx->img.paulinor1;
	}
}

static void	ft_animate_map(t_program *mlx)
{
	ft_init_var(mlx);
	ft_animate_obj(mlx);
	ft_animate_exit(mlx);
	ft_animate_enemy(mlx);
	while (mlx->y < mlx->map.winy)
	{
		while (mlx->map_done[mlx->y][mlx->x] != '\0')
		{
			if (mlx->map_done[mlx->y][mlx->x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.cptr,
					mlx->x * 80, mlx->y * 80);
			else if (mlx->map_done[mlx->y][mlx->x] == 'E' && mlx->won == 0)
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.exptr,
					mlx->x * 80, mlx->y * 80);
			else if (mlx->map_done[mlx->y][mlx->x] == 'B')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.eptr,
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
	if (mlx->dead || mlx->won == 1)
		return (1);
	if (mlx->frame == 2999)
	{
		ft_animate_map(mlx);
	}
	if (mlx->eframe == 19999)
		ft_move_enemy(mlx);
	mlx->frame++;
	mlx->eframe++;
	if (mlx->frame == 3000)
		mlx->frame = 0;
	if (mlx->eframe == 20000)
		mlx->eframe = 0;
	return (0);
}