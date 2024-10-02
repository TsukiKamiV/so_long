
#include "../includes/so_long.h"

int	my_mlx_hook_callback(int keycode, t_game *game)
{
	//on macOS
	// event: ON_DESTORY (17)
	// keycode: 1876947144 (don't know what does it mean)
	//printf("%d", keycode);
	
	//TODO: free memories, clean up etc etc
	(void)keycode;
	(void)game;
	exit(0);
}

void	ft_check_map(t_game *game)
{
	if (!ft_check_map_form(game->map.full))
	{
		ft_printf("Error\nMap is not rectangular! Exiting game.\n");
		exit (EXIT_FAILURE);
	}
	if (!ft_check_wall(game->map.full))
	{
		ft_printf("Error\nMap is not surrounded by wall.\n");
		exit (EXIT_FAILURE);
	}
	if (!ft_check_item(game))
	{
		ft_printf("Error\nInvalid elements, exiting game.\n");
		exit (EXIT_FAILURE);
	}
	if (!ft_verify_path(game->map.full))
	{
		ft_printf("Error\nCan't find valid path in this map, exiting game.\n");
		exit (EXIT_FAILURE);
	}
}

void	ft_init_window(t_game *game)
{
	//game->move_count = 0;
	//game->mlx_ptr = mlx_init();
	//ft_init_map(map, &game->map);
	//ft_check_map(game);
	//printf("There're %d carrots in this map.\n", ft_find_collectables(game));
	//game->total_collectables = ft_find_collectables(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * 16 + ((game->map.columns - 1) * 1), game->map.rows * 16 + ((game->map.rows - 1) * 1), "so_long");
	ft_init_floor(game);
	ft_init_images(game);
	//ft_put_floor(*game);
	//ft_render_map(game);
	//mlx_loop_hook(game->mlx_ptr, ft_loop_hook, game);
	//mlx_key_hook(game->win_ptr, ft_key_hook, game);
	//mlx_hook(game->win_ptr, 17, 0, my_mlx_hook_callback, game);
	//mlx_loop(game->mlx_ptr);
}


/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}*/

/*
int width = 4;
int bits_per_pixel = 1234;
int distanceInMeter = bits_per_pixel / 8
int line_length = width * distanceInMeter
int hou_de_offset = ((y * width) + x) * distanceInMeter
int shazi_de_offset = y * line_length + x * (bits_per_pixel / 8)

int offset = (y * line_length + x * (bits_per_pixel / 8));*/

