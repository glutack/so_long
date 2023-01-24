#include "so_long.h"

void	ft_move_up(t_program *mlx)
{
	mlx->falseyx = mlx->py - 1;
	if (mlx->map_done[mlx->falseyx][mlx->px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->img.y = 0;
			mlx->img.x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->falseyx][mlx->px] == '0' || mlx->map_done[mlx->falseyx][mlx->px] == 'C')
	{
		if (mlx->map_done[mlx->falseyx][mlx->px] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->falseyx][mlx->px] = 'P';
		mlx->map_done[mlx->py][mlx->px] = '0';
		ft_redraw_map(mlx->py, mlx->px, mlx->falseyx, mlx->px, mlx);
		mlx->py--;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}

void	ft_move_down(t_program *mlx)
{
	mlx->falseyx = mlx->py + 1;
	if (mlx->map_done[mlx->falseyx][mlx->px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->img.y = 0;
			mlx->img.x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->falseyx][mlx->px] == '0' || mlx->map_done[mlx->falseyx][mlx->px] == 'C')
	{
		if (mlx->map_done[mlx->falseyx][mlx->px] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->falseyx][mlx->px] = 'P';
		mlx->map_done[mlx->py][mlx->px] = '0';
		ft_redraw_map(mlx->py, mlx->px, mlx->falseyx, mlx->px, mlx);
		mlx->py++;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}

void	ft_move_left(t_program *mlx)
{
	mlx->falseyx = mlx->px - 1;
	if (mlx->map_done[mlx->py][mlx->falseyx] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->img.y = 0;
			mlx->img.x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->py][mlx->falseyx] == '0' || mlx->map_done[mlx->py][mlx->falseyx] == 'C')
	{
		if (mlx->map_done[mlx->py][mlx->falseyx] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->py][mlx->falseyx] = 'P';
		mlx->map_done[mlx->py][mlx->px] = '0';
		ft_redraw_map(mlx->py, mlx->px, mlx->py, mlx->falseyx, mlx);
		mlx->px--;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}

void	ft_move_right(t_program *mlx)
{
	mlx->falseyx = mlx->px + 1;
	if (mlx->map_done[mlx->py][mlx->falseyx] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->img.y = 0;
			mlx->img.x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->py][mlx->falseyx] == '0' || mlx->map_done[mlx->py][mlx->falseyx] == 'C')
	{
		if (mlx->map_done[mlx->py][mlx->falseyx] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->py][mlx->falseyx] = 'P';
		mlx->map_done[mlx->py][mlx->px] = '0';
		ft_redraw_map(mlx->py, mlx->px, mlx->py, mlx->falseyx, mlx);
		mlx->px++;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}