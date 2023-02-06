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
		ft_perror("Error\nCould not load sprites", mlx);
	}
}

void	ft_perror(char *str, t_program *mlx)
{
	perror(str);
	if (mlx->map_done)
	{
		ft_free_split(mlx->map_done);
		ft_free_split(mlx->map.visited);
	}
	if (mlx->mlx)
		free(mlx->mlx);
	exit(0);
}
