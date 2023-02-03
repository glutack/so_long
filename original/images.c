#include "so_long.h"

static void	ft_img_handlertwo(t_program *mlx)
{
	(*mlx).img.selene = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/selene.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.selenel = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/selenel.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.selener = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/selener.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.paulinol1 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/paulinol1.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinol2 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/paulinol2.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinol3 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/paulinol3.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinor1 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/paulinor1.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinor2 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/paulinor2.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinor3 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/paulinor3.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
}

void	ft_img_handler(t_program *mlx)
{
	(*mlx).img.wall = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/wall.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.moves = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/moves.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.path = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/path.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/exit.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit0 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/exit0.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit40 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/exit40.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit70 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/exit70.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/object.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object0 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/object0.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object40 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/object40.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object70 = mlx_xpm_file_to_image((*mlx).mlx,
			"./assets/object70.xpm", &((*mlx).img.width), &((*mlx).img.height));
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