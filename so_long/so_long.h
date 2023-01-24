#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> // open
# include <unistd.h> // read, close

//structs
typedef struct	s_img {
	int		width;
	int		height;
	int		y;
	int		x;
	int		winy;
	int		winx;
	void	*wall;
	void	*selene;
	void	*selenel;
	void	*selener;
	int		selenepos;
	void	*path;
	void	*exit;
	void	*object;
	void	*paulinor1;
	void	*paulinor2;
	void	*paulinor3;
	void	*paulinol1;
	void	*paulinol2;
	void	*paulinol3;
}				t_img;

typedef struct	s_program {
	void	*mlx;
	void	*win;
	char	**p;
	char	**map_done;
	int		py;
	int		px;
	int		falseyx;
	int		moves;
	int		collected;
	int		to_collect;
	int		end;

	t_img	img;
}				t_program;

//image related
void	ft_img_handler(t_program *mlx);
void	ft_img_eraser(t_program *mlx);
void	ft_redraw_map(int pathy, int pathx, int py, int px, t_program *mlx);


//keys
//esc = 65307 | a = 97 | w = 119 | s = 115 | d = 100|
int		ft_close_win(t_program *mlx);
int		ft_keys(int key, void *program);
void	ft_move_up(t_program *mlx);
void	ft_move_down(t_program *mlx);
void	ft_move_left(t_program *mlx);
void	ft_move_right(t_program *mlx);


//map
char	**ft_check_map(char *map, t_program *mlx);
void	ft_draw_map(char **map, int y, t_program *mlx);
void	ft_end_map(t_program *mlx);
#endif
