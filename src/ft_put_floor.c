/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:23:24 by luxu              #+#    #+#             */
/*   Updated: 2024/10/02 23:08:43 by luxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_floor(t_game *game)
{
	game->floor.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
			FLOOR_TILE_PATH, &game->floor.size.width, &game->floor.size.height);
	if (!game->floor.xpm_ptr)
	{
		ft_printf("Error\nFaild to load the floor, stopping game.\n");
		exit (EXIT_FAILURE);
	}
}

void	ft_put_floor(t_game game)
{
	t_image	floor_tile;
	int		x;
	int		y;
	int		coordinate_x;
	int		coordinate_y;

	floor_tile = game.floor;
	x = 0;
	while (x < game.map.columns)
	{
		y = 0;
		while (y < game.map.rows)
		{
			coordinate_x = x * (floor_tile.size.width + 1);
			coordinate_y = y * (floor_tile.size.height + 1);
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, \
					floor_tile.xpm_ptr, coordinate_x, coordinate_y);
			y++;
		}
		x++;
	}
}
