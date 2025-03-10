/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:46:08 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/04 23:24:18 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	*gen_background_one_link(Wind_t *wind, Map_t *map, int *pos, bool check)
{
	if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, "e.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, "w.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, "s.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "n.xpm"));
	else
		return (gen_background_corner(wind, map, pos, check));
}

void	*gen_background_three_link(Wind_t *wind, Map_t *map, int *pos, bool check)
{
	if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "nsw.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "nse.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "sew.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, "new.xpm"));
	else
		return (NULL);
}
