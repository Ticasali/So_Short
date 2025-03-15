/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:46:08 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 07:06:47 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	*gen_background_one_link(t_Wind *wind, t_Map *map, int *pos, bool c)
{
	if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
		return (load_img_block(wind, pos, c, "e.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
		return (load_img_block(wind, pos, c, "w.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
		return (load_img_block(wind, pos, c, "s.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
		return (load_img_block(wind, pos, c, "n.xpm"));
	else
		return (gen_background_corner(wind, map, pos, c));
}

void	*gen_background_three_link(t_Wind *wind, t_Map *map, int *pos, bool c)
{
	if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
		return (load_img_block(wind, pos, c, "nsw.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
		return (load_img_block(wind, pos, c, "nse.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
		return (load_img_block(wind, pos, c, "new.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
		return (load_img_block(wind, pos, c, "sew.xpm"));
	else
		return (NULL);
}
