#include "so_long.h"

static void	ft_check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'C' || str[i] == 'E'
			|| str[i] == 'P' || str[i] == 'B' || str[i] == '\n'))
		{
			perror("Error\nIllegal char in map");
			exit(0);
		}
		i++;
	}
}

static int	ft_check_ber(char *map)
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
	else
	{
		perror("Error\nIllegal extension");
		return (0);
	}
}

static void	ft_reading_map(char *map_read, char **map, int fd, t_program *mlx)
{
	map_read = get_next_line(fd);
	*map = "\0";
	while (map_read)
	{
		ft_check_chars(map_read);
		*map = ft_strjoin(*map, map_read);
		map_read = get_next_line(fd);
		mlx->img.winy++;
	}
}

static void ft_wall_check(char **map, t_program *mlx)
{
	mlx->img.x = (mlx->img.winx - 1);
	mlx->img.y = (mlx->img.winy - 1);
	while (mlx->img.x >= 0)
	{	
		if ((map[mlx->img.y][mlx->img.x] != '1') || (map[0][mlx->img.x] != '1'))
		{
			perror("Error\nMap is not closed");
			exit(0);
		}
		else
			mlx->img.x--;
	}
	mlx->img.x = (mlx->img.winx - 1);
	mlx->img.y--;
	while (mlx->img.y > 0)
	{
		if ((map[mlx->img.y][0] != '1') || (map[mlx->img.y][mlx->img.x] != '1'))
		{
			perror("Error\nMap is not closed");
			exit(0);
		}
		else
			mlx->img.y--;
	}
}

char	**ft_check_map(char *map, t_program *mlx)
{
	char	*map_read;
	char	**map_done;
	int		fd;

	mlx->img.winy = 0;
	mlx->img.winx = 0;
	if (ft_check_ber(map) == 1)
	{
		fd = open(map, O_RDONLY);
		if (!fd)
			perror("Error\nRead error");
		ft_reading_map(map_read, &map, fd, mlx);
		while (map[mlx->img.winx] != '\n')
			mlx->img.winx++;
		if (mlx->img.winx <= mlx->img.winy)
		{
			perror("Error\nMap must be rectangular");
			exit(0);
		}
		map_done = ft_split(map, '\n');
		ft_wall_check(map_done, mlx);
	}
	return (map_done);
}
