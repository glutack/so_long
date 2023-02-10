/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:22:48 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:22:49 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_img_handler_enemy(t_program *mlx)
{
	(*mlx).img.paulinol1 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinol1.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinol2 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinol2.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinol3 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinol3.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinor1 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinor1.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinor2 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinor2.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.paulinor3 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/paulinor3.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
}

static void	ft_img_handler_comp(t_program *mlx)
{
	(*mlx).img.path = mlx_xpm_file_to_image((*mlx).mlx, "./textures/path.xpm",
			&((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.wall = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/wall.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.moves = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/moves.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit0 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit0.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit40 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit40.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit70 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/exit70.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object0 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object0.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.object40 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object40.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
		(*mlx).img.object70 = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/object70.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
}

void	ft_img_handler(t_program *mlx)
{
	(*mlx).img.selene = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/selene.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.selenel = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/selenel.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.selener = mlx_xpm_file_to_image((*mlx).mlx,
			"./textures/selener.xpm", &((*mlx).img.width),
			&((*mlx).img.height));
	(*mlx).img.you = mlx_xpm_file_to_image((*mlx).mlx, "./textures/you.xpm",
			&((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.win = mlx_xpm_file_to_image((*mlx).mlx, "./textures/win.xpm",
			&((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.lose = mlx_xpm_file_to_image((*mlx).mlx, "./textures/lose.xpm",
			&((*mlx).img.width), &((*mlx).img.height));
	ft_img_handler_enemy(mlx);
	ft_img_handler_comp(mlx);
	ft_img_error(mlx);
}

void	ft_img_eraser(t_program *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.moves);
	mlx_destroy_image(mlx->mlx, mlx->img.selene);
	mlx_destroy_image(mlx->mlx, mlx->img.path);
	mlx_destroy_image(mlx->mlx, mlx->img.you);
	mlx_destroy_image(mlx->mlx, mlx->img.win);
	mlx_destroy_image(mlx->mlx, mlx->img.lose);
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
