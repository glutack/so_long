/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:23:24 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:23:25 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_program *mlx)
{
	while (mlx->map_done[mlx->y][mlx->x] != '\0')
	{
		if (mlx->map_done[mlx->y][mlx->x] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->y == mlx->map.py && mlx->x == mlx->map.px)
			ft_animate_player(mlx->y, mlx->x, mlx);
		else if ((mlx->map_done[mlx->y][mlx->x] == '0'
			|| mlx->map_done[mlx->y][mlx->x] == 'P'))
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.cptr,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'B')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.eptr,
				mlx->x * 80, mlx->y * 80);
		else if (mlx->map_done[mlx->y][mlx->x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.exptr,
				mlx->x * 80, mlx->y * 80);
		ft_update_moves(mlx);
		mlx->x++;
	}
}

void	ft_end_map(t_program *mlx)
{
	if (mlx->map_done[mlx->map.py][mlx->map.px] == 'E')
	{
		if (mlx->collected == mlx->to_collect)
		{
			mlx->won = 1;
			ft_draw_end_map(mlx);
		}
		else
			mlx->won = 2;
	}
	else if (mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
	{
		mlx->dead = 1;
		ft_draw_end_map(mlx);
	}
}

static void	ft_draw_end_msg(t_program *mlx)
{
	if (mlx->y == (mlx->map.winy / 2)
		&& mlx->x == (mlx->map.winx / 2) - 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.you,
			mlx->x * 80, mlx->y * 80);
	else if (mlx->y == (mlx->map.winy / 2) && mlx->x == (mlx->map.winx / 2))
	{
		if (mlx->dead == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.paulinol1,
				mlx->x * 80, mlx->y * 80);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene,
				mlx->x * 80, mlx->y * 80);
	}
	else if (mlx->y == (mlx->map.winy / 2) && mlx->x == (mlx->map.winx / 2) + 1)
	{
		if (mlx->dead == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.lose,
				mlx->x * 80, mlx->y * 80);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.win,
				mlx->x * 80, mlx->y * 80);
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall,
			mlx->x * 80, mlx->y * 80);
}

void	ft_draw_end_map(t_program *mlx)
{
	ft_init_var(mlx);
	mlx->x = 1;
	while (mlx->y < mlx->map.winy)
	{
		while (mlx->map_done[mlx->y][mlx->x] != '\0')
		{
			ft_draw_end_msg(mlx);
			mlx->x++;
		}
		mlx->y++;
		mlx->x = 0;
	}
}
