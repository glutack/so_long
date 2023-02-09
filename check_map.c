#include "so_long.h"

static void	ft_check_chars(char *str, int *e, int *p, t_program *mlx)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			mlx->to_collect++;
		if (str[i] == 'E')
			(*e)++;
		if (str[i] == 'P')
			(*p)++;
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'C' || str[i] == 'E'
				|| str[i] == 'P' || str[i] == 'B' || str[i] == '\n'))
			ft_perror("Error\nIllegal char in map", mlx);
		i++;
	}
}

static char	*ft_reading_map(char *map, int fd, t_program *mlx)
{
	int		e;
	int		p;
	char	*map_read;

	e = 0;
	p = 0;
	mlx->to_collect = 0;
	map_read = get_next_line(fd);
	map = ft_strdup("\0");
	while (map_read)
	{
		ft_check_chars(map_read, &e, &p, mlx);
		map = ft_strjoin(map, map_read);
		map_read = get_next_line(fd);
		mlx->map.winy++;
	}
	free(map_read);
	while (map[mlx->map.winx] != '\n')
		mlx->map.winx++;
	if (mlx->map.winx == mlx->map.winy)
		ft_perror("Error\nMap must be rectangular", mlx);
	if ((mlx->to_collect < 1) || !(e == 1) || !(p == 1))
		ft_perror("Error\nToo many or missing components in map", mlx);
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

static void	ft_check_wall(char **map, t_program *mlx)
{
	mlx->x = (mlx->map.winx - 1);
	mlx->y = (mlx->map.winy - 1);
	while (mlx->x >= 0)
	{	
		if ((map[mlx->y][mlx->x] != '1') || (map[0][mlx->x] != '1'))
			ft_perror("Error\nMap is not closed", mlx);
		else
			mlx->x--;
	}
	mlx->x = (mlx->map.winx - 1);
	while (mlx->y >= 0)
	{
		if ((map[mlx->y][0] != '1') || (map[mlx->y][mlx->x] != '1'))
			ft_perror("Error\nMap is not closed", mlx);
		else
			mlx->y--;
	}
	ft_get_positions(map, mlx->map.winy, mlx);
}

char	**ft_check_map(char *map, t_program *mlx)
{
	char	**map_done;
	int		fd;

	mlx->map.winy = 0;
	mlx->map.winx = 0;
	fd = open(map, O_RDONLY);
	if (!fd)
		ft_perror("Error\nRead error", mlx);
	map = ft_reading_map(map, fd, mlx);
	close(fd);
	map_done = ft_split(map, '\n');
	mlx->map.visited = ft_split(map, '\n');
	ft_check_wall(map_done, mlx);
	if ((ft_check_path(map_done, mlx->map.py, mlx->map.px, mlx)) == 'F')
		ft_perror("Error\nNo path available", mlx);
	ft_free_split(mlx->map.visited);
	mlx->map.visited = ft_split(map, '\n');
	free(map);
	return (map_done);
}
