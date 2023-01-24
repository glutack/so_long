#include "so_long.h"

//mlx makefile change

//					MAIN.C
//initializes mlx connection, creates window, checks map, creates map, calls keystroke functions

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_program	mlx;

		mlx.map_done = ft_check_map(argv[1], &mlx);
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
		{
			perror("Error:\nCould not initialize mlx");
			free(mlx.map_done);
			return (1);
		}
		mlx.win = mlx_new_window(mlx.mlx, mlx.img.winx * 80, mlx.img.winy * 80, "Las aventuras de Selene");
		mlx.moves = 0;
		mlx.collected = 0;
		mlx.end = 0;
		ft_img_handler(&mlx);
		ft_draw_map(mlx.map_done, mlx.img.winy, &mlx);
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