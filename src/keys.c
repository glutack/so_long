/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:23:01 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:23:02 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(t_program *mlx)
{
	ft_img_eraser(mlx);
	ft_free_split(mlx->map.visited);
	ft_free_split(mlx->map_done);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	exit(0);
	return (0);
}

void	ft_update_moves(t_program *mlx)
{
	char	*moves;
	char	*collected;
	char	*tocollect;

	moves = ft_itoa(mlx->moves);
	collected = ft_itoa(mlx->collected);
	tocollect = ft_itoa(mlx->to_collect);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.moves,
		0 * 80, 0 * 80);
	mlx_string_put(mlx->mlx, mlx->win, 25, 22, 000000, "moves");
	mlx_string_put(mlx->mlx, mlx->win, 35, 32, 000000, moves);
	mlx_string_put(mlx->mlx, mlx->win, 20, 46, 000000, "chicken");
	mlx_string_put(mlx->mlx, mlx->win, 26, 56, 000000, "wings");
	mlx_string_put(mlx->mlx, mlx->win, 19, 66, 000000, collected);
	mlx_string_put(mlx->mlx, mlx->win, 35, 66, 000000, "/");
	mlx_string_put(mlx->mlx, mlx->win, 50, 66, 000000, tocollect);
	free(moves);
	free(collected);
	free(tocollect);
}

int	ft_keys(int keycode, void *program)
{
	t_program	*mlx;

	mlx = program;
	if (keycode == 65307 || keycode == 53)
		ft_close_win(mlx);
	if (mlx->won != 1 && mlx->dead != 1)
	{
		//ft_putstr_fd("%d", keycode);
		/*if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		{
			if (keycode == 13)
				ft_move_up(program);
			else if (keycode == 0)
				ft_move_left(program);
			else if (keycode == 1)
				ft_move_down(program);
			else if (keycode == 2)
				ft_move_right(program);
		}*/
		if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		{
			if (keycode == 119) //w
				ft_move_player((-1), 0, program);
			else if (keycode == 97) //a
				ft_move_player(0, (-1), program);
			else if (keycode == 115) //s
				ft_move_player(1, 0, program);
			else if (keycode == 100) //d
				ft_move_player(0, 1, program);
		}
	}
	return (0);
}
