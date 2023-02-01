void static	ft_enemy_animation(t_program *mlx)
{

}

void static	ft_map_animation(t_program *mlx)
{
	
}

int	ft_animation(void *program)
{
	t_program	*mlx;

	mlx = program;
	if (mlx->player.dead || mlx->end)
		return (1);
	if (mlx->frame == 1999)
	{
		ft_enemy_animation
		ft_map_animation
	}
	mlx->frame++;
	if (mlx->frame == 2000)
		mlx->frame = 0;
	return (0);
}