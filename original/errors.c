#include "so_long.h"

void	ft_img_error(t_program *mlx)
{
	if (!mlx->img.wall || !mlx->img.selene || !mlx->img.path
		|| !mlx->img.exit || !mlx->img.object || !mlx->img.selener
		|| !mlx->img.selenel || !mlx->img.paulinol1
		|| !mlx->img.paulinol2 || !mlx->img.paulinol3
		|| !mlx->img.paulinor1 || !mlx->img.paulinor2
		|| !mlx->img.paulinor3)
	{
		ft_img_eraser(mlx);
		ft_perror("Error\nCould not load sprites");
	}
}

void	ft_perror(char *str)
{
	perror(str);
	exit(0);
}

/*void	ft_end_map(t_program *mlx)
{
	if (mlx->won == 1)
	{
		while (mlx->y < mlx->map.winy)
		{
			while (mlx->map_done[mlx->y][mlx->x] != '\0')
			{
				ft_print_cell(mlx);
				usleep(100);
				mlx->x++;
			}
			mlx->x = 0;
			mlx->y++;
		}
	}
}*/