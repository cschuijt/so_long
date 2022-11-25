/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering_passes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 13:32:04 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/17 13:32:04 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	categorize_map_walls(t_map *map)
{
	char	*c_map;
	size_t	y;

	y = 0;
	c_map = ft_calloc(map->size + 1, 1);
	if (!c_map)
		exit_perror("malloc error");
	ft_memset(c_map, ' ', map->size);
	ft_memset(c_map, 'W', map->width);
	ft_memset(&c_map[map->width * (map->height - 1)], 'W', map->width);
	while (y < map->height)
	{
		c_map[y * map->width] = 'W';
		c_map[((y + 1) * map->width) - 1] = 'W';
		y++;
	}
	map->render_categories = c_map;
	initial_wall_seed(map);
	recursive_walls(map);
	lava_and_pillars(map);
	north_walls(map);
	fill_floors_and_strip_walls(map);
}

void	fill_in_wall_map(t_map *map)
{
	size_t	i;

	i = 0;
	map->render_walls = ft_calloc(1, map->size + 1);
	if (!map->render_walls)
		exit_perror("malloc error");
	while (map->render_categories[i])
	{
		if (map->render_categories[i] == 'N')
			map->render_walls[i] = 60;
		if (map->render_categories[i] == 'W')
			map->render_walls[i] = determine_wall_sprite(map, i);
		i++;
	}
}
