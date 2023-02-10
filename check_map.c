/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:21:56 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:21:58 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_chars(char *str, t_program *mlx)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			mlx->to_collect++;
		if (str[i] == 'E')
			mlx->map.ey++;
		if (str[i] == 'P')
			mlx->map.ex++;
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'C' || str[i] == 'E'
				|| str[i] == 'P' || str[i] == 'B' || str[i] == '\n'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	*ft_reading_map(char *map, int fd, t_program *mlx)
{
	char	*map_read;
	char	*aux;

	mlx->map.ey = 0;
	mlx->map.ex = 0;
	mlx->to_collect = 0;
	map_read = get_next_line(fd);
	map = ft_strdup("\0");
	while (map_read)
	{
		aux = map;
		map = ft_strjoin(map, map_read);
		free(aux);
		aux = map_read;
		map_read = get_next_line(fd);
		free(aux);
		mlx->map.winy++;
	}
	if (ft_check_chars(map, mlx) == 0)
		ft_perror_reading_map(map, map_read, "Error\nIllegal char in map");
	if ((mlx->to_collect < 1) || !(mlx->map.ey == 1) || !(mlx->map.ex == 1))
		ft_perror_reading_map(map, map_read,
			"Error\nToo many or missing components in map");
	return (map);
}

static void	ft_get_positions(char **map, int y, t_program *mlx)
{
	ft_init_var(mlx);
	while ((mlx->y) < y)
	{
		while (map[mlx->y][mlx->x] != '\0')
		{
			if (map[mlx->y][mlx->x] == 'E')
			{
				mlx->map.ey = mlx->y;
				mlx->map.ex = mlx->x;
			}
			else if (map[mlx->y][mlx->x] == 'P')
			{
				mlx->map.py = mlx->y;
				mlx->map.px = mlx->x;
			}
			mlx->x++;
		}
		mlx->y++;
		mlx->x = 0;
	}
}

static int	ft_check_wall(char **map, t_program *mlx)
{
	mlx->x = (mlx->map.winx - 1);
	mlx->y = (mlx->map.winy - 1);
	while (mlx->x >= 0)
	{	
		if ((map[mlx->y][mlx->x] != '1') || (map[0][mlx->x] != '1'))
		{
			perror("Error\nMap is not closed");
			return (0);
		}
		else
			mlx->x--;
	}
	mlx->x = (mlx->map.winx - 1);
	while (mlx->y >= 0)
	{
		if ((map[mlx->y][0] != '1') || (map[mlx->y][mlx->x] != '1'))
		{
			perror("Error\nMap is not closed");
			return (0);
		}
		else
			mlx->y--;
	}
	ft_get_positions(map, mlx->map.winy, mlx);
	return (1);
}

char	**ft_check_map(char *map, t_program *mlx)
{
	char	**map_done;
	int		fd;

	mlx->map.winy = 0;
	mlx->map.winx = 0;
	fd = ft_check_fd(map);
	map = ft_reading_map(map, fd, mlx);
	while (map[mlx->map.winx] != '\n')
		mlx->map.winx++;
	if (mlx->map.winx == mlx->map.winy)
		ft_perror_map_rectangular(map, fd, "Error\nMap must be rectangular");
	close(fd);
	map_done = ft_split(map, '\n');
	mlx->map.visited = ft_split(map, '\n');
	if (ft_check_wall(map_done, mlx) == 0)
		ft_perror_check(map, map_done, "Error\nMap is not closed", mlx);
	else
	{
		if ((ft_check_path(map_done, mlx->map.py, mlx->map.px, mlx)) == 'F')
			ft_perror_check(map, map_done, "Error\nNo path available", mlx);
		ft_free_split(mlx->map.visited);
		mlx->map.visited = ft_split(map, '\n');
	}
	free(map);
	return (map_done);
}
