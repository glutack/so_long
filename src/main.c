/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:23:11 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:23:12 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_var(t_program *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
}

static void	ft_init_game(t_program *mlx)
{
	ft_init_var(mlx);
	ft_img_handler(mlx);
	mlx->map.cptr = mlx->img.object;
	mlx->map.exptr = mlx->img.exit0;
	mlx->map.eptr = mlx->img.paulinol2;
	mlx->selenepos = 0;
	mlx->moves = 0;
	mlx->dead = 0;
	mlx->collected = 0;
	mlx->frame = 0;
	mlx->eframe = 0;
	mlx->map.clap = 0;
	mlx->map.elap = 0;
	mlx->map.exlap = 0;
	mlx->won = 0;
	while (mlx->y < mlx->map.winy)
	{
		ft_draw_map(mlx);
		mlx->y++;
		mlx->x = 0;
	}
}

static void	ft_init_basics(t_program *mlx)
{
	if (!mlx->map_done)
	{
		perror("Error\nCould not load map");
		exit(0);
	}
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		ft_free_split(mlx->map_done);
		ft_free_split(mlx->map.visited);
		perror("Error\nCould not initialize MLX");
		exit(0);
	}
	mlx->win = mlx_new_window(mlx->mlx, mlx->map.winx * 80,
			mlx->map.winy * 80, "Las aventuras de Selene");
	if (!mlx->win)
	{
		ft_free_split(mlx->map_done);
		ft_free_split(mlx->map.visited);
		free(mlx->mlx);
		perror("Error\nCould not initialize window");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_program	mlx;

	if (argc == 2)
	{
		if (ft_check_ber(argv[1]) == 1)
		{
			ft_init_var(&mlx);
			mlx.collected = 0;
			mlx.won = 0;
			mlx.map_done = ft_check_map(argv[1], &mlx);
			ft_init_basics(&mlx);
			ft_init_game(&mlx);
			mlx_hook(mlx.win, 17, 0, ft_close_win, &mlx);
			mlx_key_hook(mlx.win, ft_keys, &mlx);
			mlx_loop_hook(mlx.mlx, ft_animation, &mlx);
			mlx_loop(mlx.mlx);
		}
		else
			perror("Error\nMap format must be .ber");
	}
	else
		perror("Error\nIncorrect number of arguments");
	return (0);
}
