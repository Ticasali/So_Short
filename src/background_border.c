/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_border.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:05:36 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/04 23:24:37 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	*gen_background_border(Wind_t *wind, Map_t *map, int *pos, bool check)
{
	if (pos[0] == 0 && map->map[pos[0] + 1][pos[1]] == '1')
		return (load_img_block(wind, pos, check, "nsew.xpm"));
	else if (pos[0] == 0 && map->map[pos[0] + 1][pos[1]] != '1')
		return (load_img_block(wind, pos, check, "new.xpm"));
	else if (pos[1] == 0 && map->map[pos[0]][pos[1] + 1] == '1')
		return (load_img_block(wind, pos, check, "nsew.xpm"));
	else if (pos[1] == 0 && map->map[pos[0]][pos[1] + 1] != '1')
		return (load_img_block(wind, pos, check, "nsw.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '\0'
		&& map->map[pos[0]][pos[1] - 1] == '1')
		return (load_img_block(wind, pos, check, "nsew.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '\0'
		&& map->map[pos[0]][pos[1] - 1] != '1')
		return (load_img_block(wind, pos, check, "nse.xpm"));
	else if (map->map[pos[0] + 1] == NULL && map->map[pos[0] - 1][pos[1]] == '1')
		return (load_img_block(wind, pos, check, "nsew.xpm"));
	else if (map->map[pos[0] + 1] == NULL && map->map[pos[0] - 1][pos[1]] != '1')
		return (load_img_block(wind, pos, check, "sew.xpm"));
	return (NULL);
}

void	*gen_background_corner(Wind_t *wind, Map_t *map, int *pos, bool check)
{
	if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, "ne.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "se.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, "ne.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "sw.xpm"));
	else
		return (gen_background_three_link(wind, map, pos, check));
}