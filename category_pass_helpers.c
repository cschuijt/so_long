/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   category_pass_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 14:06:53 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/20 14:06:53 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_wall_seed(t_map *map)
{
	size_t	i;

	i = map->width * 2;
	while (i < map->size - map->width * 3)
	{
		if (map->content[i] == '1' && map->sprite_categories[i] != 'W')
			if (map->content[i + 1] == '1')
				if (map->content[i + map->width] == '1')
					if (map->content[i + map->width + 1] == '1')
						map->sprite_categories[i] = 'W';
		i++;
	}
}

void	recursive_walls(t_map *map)
{
	size_t	i;
	size_t	changed;

	map->size = ft_strlen(map->content);
	i = map->width;
	changed = 0;
	while (i < map->size - map->width)
	{
		if (map->content[i] == '1' && map->sprite_categories[i] == ' ')
		{
			if (neighbors_wall(map, i) && can_be_wall(map, i))
			{
				map->sprite_categories[i] = 'W';
				changed++;
			}
		}
		i++;
	}
	if (changed)
		recursive_walls(map);
}

int	neighbors_wall(t_map *map, size_t i)
{
	if (map->sprite_categories[i + 1] == 'W')
		return (1);
	if (map->sprite_categories[i - 1] == 'W')
		return (1);
	if (map->sprite_categories[i + map->width] == 'W')
		return (1);
	if (map->sprite_categories[i - map->width] == 'W')
		return (1);
	return (0);
}

int	can_be_wall(t_map *map, size_t i)
{
	if (map->content[i + map->width] == '1')
		return (1);
	if (map->content[i - map->width] == '1')
		return (1);
	return (0);
}

void	lava_and_pillars(t_map *map)
{
	size_t	i;
	char	*loc;

	i = 0;
	while (map->content[i])
	{
		if (map->content[i] == '1' && map->sprite_categories[i] == ' ')
		{
			loc = &map->content[i];
			if (*(loc + 1) != '1' && *(loc - 1) != '1')
			{
				if (*(loc + map->width) != '1' && *(loc - map->width) != '1')
					map->sprite_categories[i] = 'P';
				else
					map->sprite_categories[i] = 'L';
			}
			else
				map->sprite_categories[i] = 'L';
		}
		i++;
	}
}
