#include "so_long.h"

void	ft_move_up(t_program *mlx)
{
	mlx->falsey = mlx->py - 1;
	if (mlx->map_done[mlx->falsey][mlx->px] == '0' || mlx->map_done[mlx->falsey][mlx->px] == 'C')
	{
		if (mlx->map_done[mlx->falsey][mlx->px] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->falsey][mlx->px] == 'P';
		mlx->map_done[mlx->py][mlx->px] == '0';
		ft_redraw_map(mlx->py, mlx->px, mlx->falsey, mlx->px, mlx);
		mlx->py--;
		mlx->moves++;
		printf("up ->%c\n", mlx->map_done[mlx->py][mlx->px]);
		printf("moves -> %d\n", mlx->moves);
	}
	/*if (mlx->map_done[mlx->falsey][mlx->px] == 'E')
	{
		mlx->end = 1;
		mlx->img.y = 0;
		mlx->img.x = 0;
		ft_end_map(mlx);
	}*/
}

void	ft_move_down(t_program *mlx)
{
	mlx->falsey = mlx->py + 1;
	//printf("%c", mlx->map_done[mlx->falsey][mlx->px]);
	if (mlx->map_done[mlx->falsey][mlx->px] == '0' || mlx->map_done[mlx->falsey][mlx->px] == 'C')
	{
		if (mlx->map_done[mlx->falsey][mlx->px] == 'C')
			mlx->collected++;
		mlx->map_done[mlx->falsey][mlx->px] == 'P';
		mlx->map_done[mlx->py][mlx->px] == '0';
		ft_redraw_map(mlx->py, mlx->px, mlx->falsey, mlx->px, mlx);
		mlx->py++;
		mlx->moves++;
		printf("down ->%c\n", mlx->map_done[mlx->py][mlx->px]);
		printf("moves -> %d\n", mlx->moves);
	}
	/*if (mlx->map_done[mlx->falsey][mlx->px] == 'E')
	{
		mlx->end = 1;
		mlx->img.y = 0;
		mlx->img.x = 0;
		ft_end_map(mlx);
	}*/
}