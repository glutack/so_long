#include "so_long.h"

//mlx makefile change

//					MAIN.C
//initializes mlx connection, creates window, checks map, creates map, calls keystroke functions

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
	else
		ft_perror("Error\nMap format must be .ber");
	return (0);
}

static void	ft_var_init(t_program *mlx)
{
	mlx->moves = 0;
	mlx->collected = 0;
	mlx->end = 0;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_program	mlx;

		ft_check_map(argv[1], &mlx);
		if (!mlx.map_done)
			ft_perror("Error\nCould not load map");
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
		{
			ft_perror("Error\nCould not initialize MLX");
			free(mlx.map_done);
		}
		mlx.win = mlx_new_window(mlx.mlx, mlx.map.winx * 80, mlx.map.winy * 80, "Las aventuras de Selene");
		ft_var_init(&mlx);
		ft_img_handler(&mlx);
		ft_draw_map(mlx.map_done, mlx.map.winy, &mlx);
		mlx_hook(mlx.win, 17, 0, ft_close_win, &mlx);
		mlx_key_hook(mlx.win, ft_keys, &mlx);
		//mlx_loop_hook(mlx.mlx, ft_animation, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		return (0);
}

//bonus
/*mlx_string_put para contador
		mlx_string_put(mlx.mlx, mlx.win, 50, 50, 0xccccff, str);
*/