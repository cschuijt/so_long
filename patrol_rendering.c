/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrol_rendering.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 00:59:41 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/28 00:59:41 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	render_patrols(t_map *map)
{
	t_patrol	*patrol;
	int			xy[2];

	patrol = map->patrols;
	while (patrol)
	{
		patrol->image = mlx_new_image(map->mlx, 48, 48);
		free(patrol->image->pixels);
		patrol->image->pixels = map->patrol_sprites[patrol->facing_offset];
		xy[0] = render_x_pos(map, patrol->pos) - 8;
		xy[1] = render_y_pos(map, patrol->pos) - 24;
		mlx_image_to_window(map->mlx, patrol->image, xy[0], xy[1]);
		mlx_set_instance_depth(&map->player->image->instances[0], 4);
		patrol = patrol->next;
	}
}
