/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:20:22 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:20:43 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_place_enemy(int mov, t_program *mlx)
{
	if (mlx->map_done[mlx->y][mlx->x] == 'B')
	{
		if (mlx->map.visited[mlx->y][mlx->x] == 'E')
			mlx->map_done[mlx->y][mlx->x] = 'E';
		else
		{							
			mlx->map_done[mlx->y][mlx->x] = '0';
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img.path, mlx->x * 80, mlx->y * 80);
		}
		if (mlx->map.visited[mlx->y][mlx->x] == 'C')
			mlx->map_done[mlx->y][mlx->x] = 'C';
		mlx->map_done[mlx->y][mlx->x + (mov)] = 'B';
	}
}

void	ft_change_elap(t_program *mlx)
{
	if (mlx->map.elap == 1)
	{
		mlx->map.elap = 0;
		mlx->map.eptr = mlx->img.paulinol1;
	}
	else
	{
		mlx->map.elap = 1;
		mlx->map.eptr = mlx->img.paulinor1;
	}
}

void	ft_move_enemy(t_program *mlx)
{
	while (mlx->map_done[mlx->y][mlx->x] != '\0')
	{
		if (mlx->map.elap == 0 && mlx->x != 0)
		{
			if (mlx->map_done[mlx->y][mlx->x - 1] != '1'
					&& mlx->map_done[mlx->y][mlx->x - 1] != 'B')
				ft_place_enemy((-1), mlx);
		}
		else if (mlx->map.elap == 1 && mlx->x != mlx->map.winx - 1)
		{
			if (mlx->map_done[mlx->y][mlx->x + 1] != '1'
					&& mlx->map_done[mlx->y][mlx->x + 1] != 'B')
			{
				ft_place_enemy(1, mlx);
				mlx->x++;
			}
		}
		mlx->x++;
	}
	if (mlx->map_done[mlx->map.py][mlx->map.px] == 'B')
	{
		mlx->dead = 1;
		ft_draw_end_map(mlx);
	}
}
