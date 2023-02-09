#include "so_long.h"

// AÑADIR FT_PRINTF A LIBFT Y CAMBIAR PRINTF

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

void	ft_init_var(t_program *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
}

static void	ft_init_game(t_program *mlx)
{
	ft_init_var(mlx);
	ft_img_handler(mlx);
	mlx->map.cptr = mlx->img.object;
	mlx->map.exptr = mlx->img.exit0;
	mlx->map.eptr = mlx->img.paulinol2;
	mlx->selenepos = 0;
	mlx->moves = 0;
	mlx->dead = 0;
	mlx->collected = 0;
	mlx->frame = 0;
	mlx->eframe = 0;
	mlx->map.clap = 0;
	mlx->map.elap = 0;
	mlx->map.exlap = 0;
	mlx->won = 0;
	while (mlx->y < mlx->map.winy)
	{
		ft_draw_map(mlx);
		mlx->y++;
		mlx->x = 0;
	}
}

static void	ft_init_basics(t_program *mlx)
{
	if (!mlx->map_done)
		ft_perror("Error\nCould not load map", mlx);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_perror("Error\nCould not initialize MLX", mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->map.winx * 80,
			mlx->map.winy * 80, "Las aventuras de Selene");
	if (!mlx->win)
		ft_perror("Error\nCould not initialize window", mlx);
}

int	main(int argc, char **argv)
{
	t_program	mlx;

	if (argc == 2)
	{
		if (ft_check_ber(argv[1]) == 1)
		{
			ft_init_var(&mlx);
			mlx.collected = 0;
			mlx.won = 0;
			mlx.map_done = ft_check_map(argv[1], &mlx);
			ft_init_basics(&mlx);
			ft_init_game(&mlx);
			mlx_hook(mlx.win, 17, 0, ft_close_win, &mlx);
			mlx_key_hook(mlx.win, ft_keys, &mlx);
			mlx_loop_hook(mlx.mlx, ft_animation, &mlx);
			mlx_loop(mlx.mlx);
		}
		else
			ft_perror("Error\nMap format must be .ber", &mlx);
	}
	else
		ft_perror("Error\nIncorrect number of arguments", &mlx);
}
