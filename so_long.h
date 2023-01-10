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
	void	*path;
}				t_img;

typedef struct	s_program {
	void	*mlx;
	void	*win;

	t_img	img;
}				t_program;

//image related
void	ft_img_handler(t_program *mlx);
void	ft_img_eraser(t_program *mlx);

//keys
//esc = 65307 | a = 97 | w = 119 | s = 115 | d = 100|
int		ft_close_win(void *program);
int		ft_keys(int key, void *program);

//map
char	**ft_check_map(char *map, t_program *mlx);
void	ft_draw_map(char **map, int y, t_program *mlx);

#endif
