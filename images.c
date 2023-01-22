#include "so_long.h"

//xpm_to_file
void	ft_img_handler(t_program *mlx)
{
	(*mlx).img.wall = mlx_xpm_file_to_image((*mlx).mlx, "./assets/wall.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.selene = mlx_xpm_file_to_image((*mlx).mlx, "./assets/selene.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.path = mlx_xpm_file_to_image((*mlx).mlx, "./assets/path.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit = mlx_xpm_file_to_image((*mlx).mlx, "./assets/exit.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object = mlx_xpm_file_to_image((*mlx).mlx, "./assets/object.xpm", &((*mlx).img.width), &((*mlx).img.height));
}

void ft_img_eraser(t_program *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.selene);
	mlx_destroy_image(mlx->mlx, mlx->img.path);
	mlx_destroy_image(mlx->mlx, mlx->img.exit);
	mlx_destroy_image(mlx->mlx, mlx->img.object);
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
			else if (map[mlx->img.y][mlx->img.x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.object, mlx->img.x * 80, mlx->img.y * 80);
			else if (map[mlx->img.y][mlx->img.x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.exit, mlx->img.x * 80, mlx->img.y * 80);
			else if (map[mlx->img.y][mlx->img.x] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene, mlx->img.x * 80, mlx->img.y * 80);
				mlx->py = mlx->img.y;
				mlx->px = mlx->img.x;
			}
			mlx->img.x++;
		}
		mlx->img.y++;
		mlx->img.x = 0; 
	}
}

void	ft_redraw_map(int pathy, int pathx, int py, int px, t_program *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path, pathx * 80, pathy * 80);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene, px * 80, py * 80);
}

void	ft_end_map(t_program *mlx)
{
	if (mlx->end == 1)
	{
		/*mlx->map_done[mlx->falsey][mlx->px] == 'P';
		mlx->map_done[mlx->py][mlx->px] == '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path, pathx * 80, pathy * 80);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene, px * 80, py * 80);		
		mlx->py--;
		mlx->moves++;*/
		while (mlx->img.y < mlx->img.winy)
		{
			while (mlx->map_done[mlx->img.y][mlx->img.x] != '\0')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall, mlx->img.x * 80, mlx->img.y * 80);
				mlx->img.x++;
			}
			mlx->img.x = 0;
			mlx->img.y++;
		}
	}
}