/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:22:09 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:22:32 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_fd(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (!fd)
	{
		perror("Error\nRead error");
		exit(0);
	}
	return (fd);
}

int	ft_check_ber(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	if (map[i] == 'r')
	{
		i--;
		if (map[i] == 'e')
		{
			i--;
			if (map[i] == 'b')
			{
				i--;
				if (map[i] == '.')
					return (1);
			}
		}
	}
	return (0);
}

char	ft_check_path(char **map, int y, int x, t_program *mlx)
{
	if ((mlx->won == 1) && (mlx->collected == mlx->to_collect))
		return ('T');
	if ((x > mlx->map.winx || y > mlx->map.winy || x < 0 || y < 0)
		|| mlx->map.visited[y][x] == 'T' || map[y][x] == '1')
		return ('F');
	if (map[y][x] == 'C')
		mlx->collected++;
	if (map[y][x] == 'E')
		mlx->won++;
	mlx->map.visited[y][x] = 'T';
	if (ft_check_path(map, y, (x + 1), mlx) == 'T'
		|| ft_check_path(map, y, (x - 1), mlx) == 'T'
		|| ft_check_path(map, (y + 1), x, mlx) == 'T'
		|| ft_check_path(map, (y - 1), x, mlx) == 'T')
		return ('T');
	return ('F');
}
