#include "so_long.h"

void	ft_move_up(t_program *mlx)
{
	mlx->falseyx = mlx->map.py - 1;
	if (mlx->map_done[mlx->falseyx][mlx->map.px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->y = 0;
			mlx->x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->falseyx][mlx->map.px] == '0' || mlx->map_done[mlx->falseyx][mlx->map.px] == 'C')
	{
		if (mlx->map_done[mlx->falseyx][mlx->map.px] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->falseyx][mlx->map.px] = 'P';
		mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		ft_redraw_map(mlx->falseyx, mlx->map.px, mlx);
		mlx->map.py--;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}

void	ft_move_down(t_program *mlx)
{
	mlx->falseyx = mlx->map.py + 1;
	if (mlx->map_done[mlx->falseyx][mlx->map.px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->y = 0;
			mlx->x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->falseyx][mlx->map.px] == '0' || mlx->map_done[mlx->falseyx][mlx->map.px] == 'C')
	{
		if (mlx->map_done[mlx->falseyx][mlx->map.px] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->falseyx][mlx->map.px] = 'P';
		mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		ft_redraw_map(mlx->falseyx, mlx->map.px, mlx);
		mlx->map.py++;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}

void	ft_move_left(t_program *mlx)
{
	mlx->falseyx = mlx->map.px - 1;
	if (mlx->map_done[mlx->map.py][mlx->falseyx] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->y = 0;
			mlx->x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->map.py][mlx->falseyx] == '0' || mlx->map_done[mlx->map.py][mlx->falseyx] == 'C')
	{
		if (mlx->map_done[mlx->map.py][mlx->falseyx] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->map.py][mlx->falseyx] = 'P';
		mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		ft_redraw_map(mlx->map.py, mlx->falseyx, mlx);
		mlx->map.px--;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}

void	ft_move_right(t_program *mlx)
{
	mlx->falseyx = mlx->map.px + 1;
	if (mlx->map_done[mlx->map.py][mlx->falseyx] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->end = 1;
			mlx->y = 0;
			mlx->x = 0;
			ft_end_map(mlx);
		}
	}
	if (mlx->map_done[mlx->map.py][mlx->falseyx] == '0' || mlx->map_done[mlx->map.py][mlx->falseyx] == 'C')
	{
		if (mlx->map_done[mlx->map.py][mlx->falseyx] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->map.py][mlx->falseyx] = 'P';
		mlx->map_done[mlx->map.py][mlx->map.px] = '0';
		ft_redraw_map(mlx->map.py, mlx->falseyx, mlx);
		mlx->map.px++;
		mlx->moves++;
		printf("moves -> %d || ", mlx->moves);
		printf("collected -> %d/%d\n", mlx->collected, mlx->to_collect);
	}
}