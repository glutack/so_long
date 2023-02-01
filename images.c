#include "so_long.h"

//xpm_to_file
void	ft_img_handler(t_program *mlx)
{
	(*mlx).img.wall = mlx_xpm_file_to_image((*mlx).mlx, "./assets/wall.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.path = mlx_xpm_file_to_image((*mlx).mlx, "./assets/path.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.exit = mlx_xpm_file_to_image((*mlx).mlx, "./assets/exit.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.object = mlx_xpm_file_to_image((*mlx).mlx, "./assets/object.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.selene = mlx_xpm_file_to_image((*mlx).mlx, "./assets/selene.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.selenel = mlx_xpm_file_to_image((*mlx).mlx, "./assets/selenel.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.selener = mlx_xpm_file_to_image((*mlx).mlx, "./assets/selener.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.paulinol1 = mlx_xpm_file_to_image((*mlx).mlx, "./assets/paulinol1.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.paulinol2 = mlx_xpm_file_to_image((*mlx).mlx, "./assets/paulinol2.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.paulinol3 = mlx_xpm_file_to_image((*mlx).mlx, "./assets/paulinol3.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.paulinor1 = mlx_xpm_file_to_image((*mlx).mlx, "./assets/paulinor1.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.paulinor2 = mlx_xpm_file_to_image((*mlx).mlx, "./assets/paulinor2.xpm", &((*mlx).img.width), &((*mlx).img.height));
	(*mlx).img.paulinor3 = mlx_xpm_file_to_image((*mlx).mlx, "./assets/paulinor3.xpm", &((*mlx).img.width), &((*mlx).img.height));
	ft_img_error(mlx);
}

void ft_img_eraser(t_program *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.selene);
	mlx_destroy_image(mlx->mlx, mlx->img.path);
	mlx_destroy_image(mlx->mlx, mlx->img.exit);
	mlx_destroy_image(mlx->mlx, mlx->img.object);
	mlx_destroy_image(mlx->mlx, mlx->img.selener);
	mlx_destroy_image(mlx->mlx, mlx->img.selenel);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinol1);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinol2);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinol3);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinor1);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinor2);
	mlx_destroy_image(mlx->mlx, mlx->img.paulinor3);
}

void	ft_draw_map(char **map, int y, t_program *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
	while ((mlx->y) < y)
	{
		while (map[mlx->y][mlx->x] != '\0')
		{
			if (map[mlx->y][mlx->x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall, mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path, mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.object, mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.exit, mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'B')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.paulinor1, mlx->x * 80, mlx->y * 80);
			else if (map[mlx->y][mlx->x] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selene, mlx->x * 80, mlx->y * 80);
				mlx->img.selenepos = 0;
				mlx->map.py = mlx->y;
				mlx->map.px = mlx->x;
			}
			mlx->x++;
		}
		mlx->y++;
		mlx->x = 0; 
	}
}

void	ft_redraw_map(int y, int x, t_program *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.path, mlx->map.px * 80, mlx->map.py * 80);
	if (mlx->img.selenepos == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selener, x * 80, y * 80);
		mlx->img.selenepos = 0;
	}
	else if (mlx->img.selenepos == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.selenel, x * 80, y * 80);
		mlx->img.selenepos = 1;
	}
}

void	ft_end_map(t_program *mlx)
{
	if (mlx->end == 1)
	{
		while (mlx->y < mlx->map.winy)
		{
			while (mlx->map_done[mlx->y][mlx->x] != '\0')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wall, mlx->x * 80, mlx->y * 80);
				mlx->x++;
			}
			mlx->x = 0;
			mlx->y++;
		}
	}
}