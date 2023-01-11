#include "so_long.h"

//mlx makefile change

//					MAIN.C
//initializes mlx connection, creates window, checks map, creates map, calls keystroke functions

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_program	mlx;
		char	**map_done;
	
		mlx.mlx = mlx_init();
		map_done = ft_check_map(argv[1], &mlx);
		mlx.win = mlx_new_window(mlx.mlx, mlx.img.winx * 80, mlx.img.winy * 80, "Las aventuras de Selene");
		ft_img_handler(&mlx);
		ft_draw_map(map_done, mlx.img.winy, &mlx);
		mlx_hook(mlx.win, 17, 0, ft_close_win, &mlx);
		mlx_key_hook(mlx.win, ft_keys, &mlx);
		//mlx_key_hook(mlx.win, ft_close_win, 27);
		mlx_loop(mlx.mlx);
	}
	else
		return (0);
}

//bonus
/*mlx_string_put para contador
		mlx_string_put(mlx.mlx, mlx.win, 50, 50, 0xccccff, str);
*/