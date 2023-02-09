#include "so_long.h"

static int	ft_check_chars(char *str, int *e, int *p, t_program *mlx)
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
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	*ft_reading_map(char *map, int fd, t_program *mlx)
{
	int		e;
	int		p;
	char	*map_read;
	char	*aux;

	e = 0;
	p = 0;
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
	if (ft_check_chars(map, &e, &p, mlx) == 0)
	{
		free(map);
		perror("Error\nIllegal char in map");
		exit(0);
	}
	if ((mlx->to_collect < 1) || !(e == 1) || !(p == 1))
	{
		free(map_read);
		free(map);
		perror("Error\nToo many or missing components in map");
		exit (0);
	}
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

static int	ft_check_fd(char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	if (!fd)
	{
		perror("Error\nRead error");
		exit(0);
	}
	return (fd);
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
	{
		free(map);
		close(fd);
		perror("Error\nMap must be rectangular");
		exit(0);
	}
	close(fd);
	map_done = ft_split(map, '\n');
	mlx->map.visited = ft_split(map, '\n');
	if (ft_check_wall(map_done, mlx) == 0)
	{
		free(map);
		ft_free_split(map_done);
		ft_free_split(mlx->map.visited);
		perror("Error\nNo path available");
		exit (0);
	}
	else
	{
		if ((ft_check_path(map_done, mlx->map.py, mlx->map.px, mlx)) == 'F')
		{
			free(map);
			ft_free_split(map_done);
			ft_free_split(mlx->map.visited);
			perror("Error\nNo path available");
			exit (0);
		}
		ft_free_split(mlx->map.visited);
		mlx->map.visited = ft_split(map, '\n');
	}
	free(map);
	return (map_done);
}
