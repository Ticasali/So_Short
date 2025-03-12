/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:52:08 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 03:13:37 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

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
	ctrl->PS->left = false;
	ctrl->PS->right = false;
	ctrl->PS->Dir = true;
}
