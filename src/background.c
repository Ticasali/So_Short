/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:21:46 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/09 22:20:51 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	*gen_background(Wind_t *wind, Map_t *map, int *pos, bool check)
{
	if ((pos[0] == 0 && map->map[pos[0] + 1] == NULL) 
		|| (pos[0] == 0 && map->map[pos[0]][pos[1] + 1] == '\0') 
		|| (pos[1] == 0 && map->map[pos[0] + 1] == NULL) 
		|| (pos[1] == 0 && map->map[pos[0]][pos[1] + 1] == '\0'))
		return (load_img_block(wind, pos, check, "nsew.xpm"));
	else if (pos[0] == 0 || pos[1] == 0
		|| map->map[pos[0]][pos[1] + 1] == '\0'
		|| map->map[pos[0] + 1] == NULL)
		return (gen_background_corner(wind, map, pos, check));
	else
		return (gen_background_special_case(wind, map, pos, check));
}

void	*gen_background_special_case(Wind_t *wind, Map_t *map, int *pos, bool check)
{
	if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "nsew.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] == '1'
		&& map->map[pos[0]][pos[1] - 1] == '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, "ew.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] == '1'
		&& map->map[pos[0] - 1][pos[1]] == '1')
			return (load_img_block(wind, pos, check, "ns.xpm"));
	else if (map->map[pos[0]][pos[1] + 1] != '1'
		&& map->map[pos[0]][pos[1] - 1] != '1'
		&& map->map[pos[0] + 1][pos[1]] != '1'
		&& map->map[pos[0] - 1][pos[1]] != '1')
			return (load_img_block(wind, pos, check, ".xpm"));
	else
		return (gen_background_one_link(wind, map, pos, check));
}
