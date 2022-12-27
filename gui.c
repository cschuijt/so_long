/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 22:51:14 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/22 22:51:14 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_gui(t_map *map)
{
	size_t	i;

	sprite_buffer_to_image(map->gui_bg_sprites[0], map->background, 16, 16);
	sprite_buffer_to_image(map->gui_bg_sprites[3], map->background, 16, 48);
	sprite_buffer_to_image(map->gui_bg_sprites[6], map->background, 16, 80);
	i = 1;
	while (i < map->width - 2)
	{
		sprite_buffer_to_image(map->gui_bg_sprites[1], \
								map->background, (i * 32) + 16, 16);
		sprite_buffer_to_image(map->gui_bg_sprites[4], \
								map->background, (i * 32) + 16, 48);
		sprite_buffer_to_image(map->gui_bg_sprites[7], \
								map->background, (i * 32) + 16, 80);
		i++;
	}
	sprite_buffer_to_image(map->gui_bg_sprites[2], map->background, \
							(i * 32) + 16, 16);
	sprite_buffer_to_image(map->gui_bg_sprites[5], map->background, \
							(i * 32) + 16, 48);
	sprite_buffer_to_image(map->gui_bg_sprites[8], map->background, \
							(i * 32) + 16, 80);
	render_gui_strings(map);
}

void	render_gui_strings(t_map *map)
{
	size_t	xy[2];
	char	*collectible_count;

	collectible_count = ft_itoa(map->col_total);
	xy[0] = 36;
	xy[1] = 26;
	string_to_image(map->map_name, map->background, map->gui_charset, xy);
	xy[0] = 36;
	xy[1] = 50;
	string_to_image("Moves:", map->background, map->gui_charset, xy);
	xy[0] = 36;
	xy[1] = 74;
	string_to_image("Gold:", map->background, map->gui_charset, xy);
	xy[0] = 136;
	string_to_image("/", map->background, map->gui_charset, xy);
	xy[0] = 156;
	string_to_image(collectible_count, map->background, map->gui_charset, xy);
}

void	update_gui(t_map *map)
{
	(void) map;
}
