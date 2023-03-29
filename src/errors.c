/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:22:37 by irmoreno          #+#    #+#             */
/*   Updated: 2023/02/10 12:22:38 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		perror("Error\nCould not load sprites");
		ft_close_win(mlx);
	}
}

void	ft_perror_map_rectangular(char *map, int fd, char *str)
{
	free(map);
	close(fd);
	perror(str);
	exit(0);
}

void	ft_perror_reading_map(char *map, char *map_read, char *str)
{
	free(map_read);
	free(map);
	perror(str);
	exit(0);
}

void	ft_perror_check(char *map, char **map_done, char *str, t_program *mlx)
{
	free(map);
	ft_free_split(map_done);
	ft_free_split(mlx->map.visited);
	perror(str);
	exit(0);
}
