#include "so_long.h"

static void	ft_check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'C' || str[i] == 'E'
			|| str[i] == 'P' || str[i] == 'B' || str[i] == '\n'))
			perror("Map error: Illegal char.");
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
	return (0);
}

void	ft_draw_map(char **map, int y, t_program *mlx)
{
	mlx->img.y = 0;
	mlx->img.x = 0;
	while ((mlx->img.y) < y)
	{
		while (map[mlx->img.y][mlx->img.x] != '\0')
		{
			if (map[mlx->img.y][mlx->img.x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall, mlx->img.x * 80, mlx->img.y * 80);
			else if (map[mlx->img.y][mlx->img.x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path, mlx->img.x * 80, mlx->img.y * 80);
			else if (map[mlx->img.y][mlx->img.x] == 'C' || map[mlx->img.y][mlx->img.x] == 'E' || map[mlx->img.y][mlx->img.x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene, mlx->img.x * 80, mlx->img.y * 80);
			mlx->img.x++;
		}
		mlx->img.y++;
		mlx->img.x = 0;
	}
}

static char	*ft_reading_map(char *map_read, char **map, int fd, t_program *mlx)
{
	ft_check_chars(map_read);
	*map = ft_strjoin(*map, map_read);
	map_read = get_next_line(fd);
	mlx->img.winy++;
	return (map_read);
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
			perror("Read error");
		map_read = get_next_line(fd);
		map = "\0";
		while (map_read)
			map_read = ft_reading_map(map_read, &map, fd, mlx);
		while (map[mlx->img.winx] != '\n')
			mlx->img.winx++;
		map_done = ft_split(map, '\n');
		if (mlx->img.winx <= mlx->img.winy)
		{
			perror("Map error: Map must be rectangular.");
			exit(0);
		}
	}
	else
		perror("File error: Illegal extension.");
	return (map_done);
}
