/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shadow_sprite_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 15:58:38 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/01 15:58:38 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_in_floor_shadow(t_map *map, size_t i)
{
	if (should_have_shadow(map, i - map->width))
	{
		if (should_have_shadow(map, i - 1))
			small_corner_floor_shadow(map, i);
		else
			continuous_w_floor_shadow(map, i);
	}
	else if (should_have_shadow(map, i + map->width))
	{
		if (should_have_shadow(map, i + 1))
			corner_floor_shadow(map, i);
		else
			ending_w_floor_shadow(map, i);
	}
	else
	{
		if (should_have_shadow(map, i - 1))
			continuous_n_floor_shadow(map, i);
		else
			ending_n_floor_shadow(map, i);
	}
}

void	corner_floor_shadow(t_map *map, size_t i)
{
	size_t	sprite;

	sprite = (size_t)(unsigned char) map->render_terrain[i];
	if (sprite == 64)
		map->render_shadows[i] = 0;
	if (sprite == 79 || sprite == 154)
		map->render_shadows[i] = 1;
	if (sprite == 94 || sprite == 68 || sprite == 113)
		map->render_shadows[i] = 2;
	if (sprite == 65 || sprite == 96 || sprite == 99)
		map->render_shadows[i] = 3;
	if (sprite == 66 || sprite == 82)
		map->render_shadows[i] = 4;
}

void	small_corner_floor_shadow(t_map *map, size_t i)
{
	size_t	sprite;

	sprite = (size_t)(unsigned char) map->render_terrain[i];
	if (sprite == 79 || sprite == 64 || sprite == 94 || sprite == 65)
		map->render_shadows[i] = 25;
	if (sprite == 154 || sprite == 82 || sprite == 96 || sprite == 68)
		map->render_shadows[i] = 25;
	if (sprite == 66 || sprite == 113 || sprite == 99)
		map->render_shadows[i] = 25;
	if (sprite == 95 || sprite == 83 || sprite == 69 || sprite == 67)
		map->render_shadows[i] = 26;
	if (sprite == 80 || sprite == 97 || sprite == 111 || sprite == 81)
		map->render_shadows[i] = 27;
	if (sprite == 114)
		map->render_shadows[i] = 28;
}
