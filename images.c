#include "so_long.h"

static void	ft_img_handlertwo(t_program *mlx)
{
	int	size;

	size = SIZE;
	(*mlx).img.path = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/path.xpm", &size, &size);
	(*mlx).img.selene = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/selene.xpm", &size, &size);
	(*mlx).img.selenel = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/selenel.xpm", &size, &size);
	(*mlx).img.selener = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/selener.xpm", &size, &size);
	(*mlx).img.paulinol1 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinol1.xpm", &size, &size);
	(*mlx).img.paulinol2 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinol2.xpm", &size, &size);
	(*mlx).img.paulinol3 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinol3.xpm", &size, &size);
	(*mlx).img.paulinor1 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinor1.xpm", &size, &size);
	(*mlx).img.paulinor2 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinor2.xpm", &size, &size);
	(*mlx).img.paulinor3 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinor3.xpm", &size, &size);
}

void	ft_img_handler(t_program *mlx)
{
	int	size;

	size = SIZE;
	(*mlx).img.wall = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/wall.xpm", &size, &size);
	(*mlx).img.moves = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/moves.xpm", &size, &size);
	(*mlx).img.exit = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit.xpm", &size, &size);
	(*mlx).img.exit0 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit0.xpm", &size, &size);
	(*mlx).img.exit40 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit40.xpm", &size, &size);
	(*mlx).img.exit70 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit70.xpm", &size, &size);
	(*mlx).img.object = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object.xpm", &size, &size);
	(*mlx).img.object0 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object0.xpm", &size, &size);
	(*mlx).img.object40 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object40.xpm", &size, &size);
	(*mlx).img.object70 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object70.xpm", &size, &size);
	ft_img_handlertwo(mlx);
	ft_img_error(mlx);
}

void	ft_img_eraser(t_program *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.moves);
	mlx_destroy_image(mlx->mlx, mlx->img.selene);
	mlx_destroy_image(mlx->mlx, mlx->img.path);
	mlx_destroy_image(mlx->mlx, mlx->img.exit);
	mlx_destroy_image(mlx->mlx, mlx->img.exit0);
	mlx_destroy_image(mlx->mlx, mlx->img.exit40);
	mlx_destroy_image(mlx->mlx, mlx->img.exit70);
	mlx_destroy_image(mlx->mlx, mlx->img.object);
	mlx_destroy_image(mlx->mlx, mlx->img.object0);
	mlx_destroy_image(mlx->mlx, mlx->img.object40);
	mlx_destroy_image(mlx->mlx, mlx->img.object70);
	mlx_destroy_image(mlx->mlx, mlx->img.selener);
	mlx_destroy_image(mlx->mlx, mlx->img.selenel);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinol1);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinol2);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinol3);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinor1);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinor2);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinor3);
}
