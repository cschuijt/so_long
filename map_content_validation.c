/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_content_validation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:57:58 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/12/27 20:57:58 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_invalid_characters(char c);

// Checks the map for invalid characters, as well as for invalid start,
// exit and collectible counts. A valid map has exactly one player,
// exactly one exit and at least one collectible on it.
void	validate_map_content(char *map)
{
	size_t	starts;
	size_t	exits;
	size_t	collects;

	starts = 0;
	exits = 0;
	collects = 0;
	while (*map)
	{
		if (*map == 'P')
			starts++;
		else if (*map == 'E')
			exits++;
		else if (*map == 'C')
			collects++;
		else
			check_invalid_characters(*map);
		map++;
	}
	if (starts != 1)
		exit_message("map does not have exactly one starting position");
	if (exits != 1)
		exit_message("map does not have exactly one exit");
	if (collects < 1)
		exit_message("map does not have at least one collectible");
}

void	check_invalid_characters(char c)
{
	if (c != '1' && c != '0' && c != '\n')
		if (c != 'U' && c != 'D' && c != 'L' && c != 'R')
			exit_message("map contains illegal characters");
}
