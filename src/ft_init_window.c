/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:14:34 by luxu              #+#    #+#             */
/*   Updated: 2024/10/03 21:52:53 by luxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	my_mlx_hook_callback(int keycode, t_game *game)
{
	//TODO: free memories, clean up etc etc
	(void)keycode;
	(void)game;
	exit(0);
}

void	ft_check_map(t_map *map)
{
	if (!ft_check_map_form(map->full, &map->columns, &map->rows))
	{
		ft_printf("Error\nMap is not rectangular! Exiting game.\n");
		exit (EXIT_FAILURE);
	}
	if (!ft_check_wall(map->full, map->columns, map->rows))
	{
		ft_printf("Error\nMap is not surrounded by wall.\n");
		exit (EXIT_FAILURE);
	}
	if (ft_check_item(*map) != 1)
	{
		ft_printf("Error\nInvalid elements, exiting game.\n");
		exit (EXIT_FAILURE);
	}
	if (!ft_verify_path(map->full))
	{
		ft_printf("Error\nCan't find valid path in this map, exiting game.\n");
		exit (EXIT_FAILURE);
	}
}

void	ft_init_window(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * 16 + \
			((game->map.columns - 1) * 1), game->map.rows * 16 + \
			((game->map.rows - 1) * 1), "so_long");
	ft_init_floor(game);
	ft_init_images(game);
}
