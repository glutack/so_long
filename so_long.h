#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> // open
# include <unistd.h> // read, close, usleep

# define SIZE 80


//structs
typedef struct s_img {
	int		width;
	int		height;
	void	*wall;
	void	*moves;
	void	*selene;
	void	*selenel;
	void	*selener;
	int		selenepos;
	void	*path;
	void	*exit;
	void	*exit0;
	void	*exit40;
	void	*exit70;
	void	*object;
	void	*object0;
	void	*object40;
	void	*object70;
	void	*paulinor1;
	void	*paulinor2;
	void	*paulinor3;
	void	*paulinol1;
	void	*paulinol2;
	void	*paulinol3;
}				t_img;

typedef struct s_map {
	int		winy;
	int		winx;
	int		py;
	int		px;
	int		ey;
	int		ex;
	int		clap;
	int		elap;
	int		exlap;
	void	*cptr;
	void	*eptr;
	void	*exptr;
	char	**visited;

}				t_map;

typedef struct s_program {
	void		*mlx;
	void		*win;
	char		**map_done;
	int			y;
	int			x;
	int			falseyx;
	int			moves;
	int			collected;
	int			to_collect;
	int			won;
	int			dead;
	int			frame;
	int			eframe;

	t_img		img;
	t_map		map;
}				t_program;

//image related
void	ft_img_handler(t_program *mlx); //
void	ft_img_eraser(t_program *mlx);
int		ft_animation(void *program);
void	ft_animate_player(int py, int px, t_program *mlx);
void	ft_move_enemy(t_program *mlx);

//error
int		ft_check_ber(char *map);
void	ft_perror(char *str, t_program *mlx);
void	ft_img_error(t_program *mlx);

//keys
int		ft_close_win(t_program *mlx);
int		ft_keys(int key, void *program);
void	ft_move_updown(int m, t_program *mlx);
void	ft_move_leftright(int m, t_program *mlx);
/*void	ft_move_up(t_program *mlx);
void	ft_move_down(t_program *mlx);
void	ft_move_left(t_program *mlx);
void	ft_move_right(t_program *mlx);*/

//map
char	**ft_check_map(char *map, t_program *mlx); //
char	ft_check_path(char **map, int y, int x, t_program *mlx);
void	ft_draw_p(t_program *mlx);
void	ft_draw_map(t_program *mlx);
void	ft_draw_end_map(t_program *mlx);
void	ft_end_map(t_program *mlx);

//other
void	ft_init_var(t_program *mlx); //
void	ft_update_moves(t_program *mlx); //
#endif
