#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> // open
# include <unistd.h> // read, close

//structs
typedef struct s_img {
	int		width;
	int		height;
	void	*wall;
	void	*moves;
	void	*selene;
	void	*selenel;
	void	*selener;
	void	*you;
	void	*win;
	void	*lose;
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
	void	*mlx;
	void	*win;
	char	**map_done;
	int		selenepos;
	int		y;
	int		x;
	int		moves;
	int		collected;
	int		to_collect;
	int		won;
	int		dead;
	int		frame;
	int		eframe;

	t_img	img;
	t_map	map;
}				t_program;

//image related
void	ft_img_handler(t_program *mlx);
void	ft_img_eraser(t_program *mlx);

//animation
int		ft_animation(void *program);
void	ft_move_enemy(t_program *mlx);
void	ft_change_elap(t_program *mlx);
void	ft_animate_player(int y, int x, t_program *mlx);

//error
void	ft_img_error(t_program *mlx);
void	ft_perror_reading_map(char *map, char *map_read, char *str);
void	ft_perror_check(char *map, char **map_done, char *str, t_program *mlx);
void	ft_perror_map_rectangular(char *map, int fd, char *str);

//keys
int		ft_close_win(t_program *mlx);
int		ft_keys(int key, void *program);
void	ft_move_player(int movy, int movx, t_program *mlx);

//map
char	**ft_check_map(char *map, t_program *mlx);
void	ft_draw_map(t_program *mlx);
void	ft_end_map(t_program *mlx);
void	ft_draw_end_map(t_program *mlx);

//check stuff
int		ft_check_fd(char *map);
int		ft_check_ber(char *map);
char	ft_check_path(char **map, int y, int x, t_program *mlx);

//other
void	ft_init_var(t_program *mlx);
void	ft_update_moves(t_program *mlx);
#endif
