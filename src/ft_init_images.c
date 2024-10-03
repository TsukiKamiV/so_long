/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:37:01 by luxu              #+#    #+#             */
/*   Updated: 2024/10/03 13:43:17 by luxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_image(t_game *game, t_image *img, char *path)
{
	img->xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
			path, &img->size.width, &img->size.height);
}

void	ft_init_images(t_game *game)
{
	ft_load_image(game, &game->person, PERSON_PATH);
	ft_load_image(game, &game->person_front, PERSON_FRONT_PATH);
	ft_load_image(game, &game->person_back, PERSON_BACK_PATH);
	ft_load_image(game, &game->person_right, PERSON_RIGHT_PATH);
	ft_load_image(game, &game->person_left, PERSON_LEFT_PATH);
	ft_load_image(game, &game->carrot, CARROTS_PATH);
	ft_load_image(game, &game->wall, WALL_PATH);
	ft_load_image(game, &game->exit, EXIT_PATH);
	if (!game->person.xpm_ptr || !game->carrot.xpm_ptr || \
			!game->wall.xpm_ptr || !game->exit.xpm_ptr)
	{
		ft_printf("Error\nFaild to load the images, stopping game\n");
		exit (EXIT_FAILURE);
	}
}
