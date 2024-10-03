/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:10:35 by luxu              #+#    #+#             */
/*   Updated: 2024/10/02 19:13:27 by luxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_map(char *map, t_map *map_struct)
{
	int		fd;
	char	*line_tmp;
	char	*map_tmp;

	fd = open(map, O_RDONLY);
	ft_map_error_exit(fd);
	map_struct->rows = 0;
	map_tmp = ft_strdup("");
	while (1)
	{
		line_tmp = get_next_line(fd);
		if (line_tmp == NULL)
			break ;
		map_struct->columns = ft_strlen(line_tmp) - 1;
		map_tmp = ft_strjoin(map_tmp, line_tmp);
		free (line_tmp);
		map_struct->rows++;
	}
	close(fd);
	ft_empty_line(map_tmp);
	map_struct->full = ft_split(map_tmp, '\n');
	free (map_tmp);
}

int	ft_find_collectables(t_game *game)
{
	char	**map;
	int		line;
	int		i;

	line = 0;
	game->total_collectables = 0;
	map = game->map.full;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (map[line][i] == 'C')
				game->total_collectables++;
			else if (map[line][i] == 'P')
			{
				game->person_pos.x = i;
				game->person_pos.y = line;
			}
			i++;
		}
		line++;
	}
	return (game->total_collectables);
}

void	ft_map_error_exit(int fd)
{
	if (fd == -1)
	{
		ft_printf("Error Loading Map\n");
		exit (EXIT_FAILURE);
	}
}
