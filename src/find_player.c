/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:14:33 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 04:02:56 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

size_t	find_player(char **map, bool check)
{
	size_t	ct_y;
	size_t	ct_x;

	ct_y = 0;
	while (map[ct_y] != NULL)
	{
		ct_x = 0;
		while (map[ct_y][ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'P')
			{
				if (check == true)
					return (ct_y);
				else
					return (ct_x);
			}
			++ct_y;
			++ct_x;
		}
	}
	return (0);
}

void	load_pos_player(Control_t *ctrl)
{
	size_t	ct;
	Map_t	*map;
	size_t	ct_y;
	size_t	ct_x;

	ct = -1;
	map = ctrl->MS;
	while (++ct < ctrl->Statement)
		map = map->next;
	ct_y = find_player(map->map, true);
	ct_x = find_player(map->map, false);
	ctrl->PS->x = 64 * ct_x - 368;
	ctrl->PS->y = 64 * ct_y - 256;
	ctrl->PS->XminH = 64 * ct_x;
	ctrl->PS->XmaxH = 64 * ct_x + 128;
	ctrl->PS->YminH = 64 * ct_y - 64;
	ctrl->PS->YmaxH = 64 * ct_y + 64;
	ctrl->PS->Up = 0;
	ctrl->PS->Move = 0;
	ctrl->PS->Up_Val = 128;
}
