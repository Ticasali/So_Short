/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_boss_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:04:19 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:48:05 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	load_pos_boss(t_Control *ctrl)
{
	size_t	ct;
	t_Map	*map;
	size_t	ct_y;
	size_t	ct_x;

	ct = -1;
	map = ctrl->ms;
	while (++ct < ctrl->statement)
		map = map->next;
	ct_y = find_boss(map->map, true);
	ct_x = find_boss(map->map, false);
	ctrl->bs->x = 64 * ct_x - 368;
	ctrl->bs->y = 64 * ct_y - 320;
	ctrl->bs->xminh = 64 * ct_x;
	ctrl->bs->xmaxh = 64 * ct_x + 128;
	ctrl->bs->yminh = 64 * ct_y - 64;
	ctrl->bs->ymaxh = 64 * ct_y + 64;
	ctrl->bs->up = 0;
	ctrl->bs->move = true;
	ctrl->bs->up_val = 128;
	ctrl->bs->left = false;
	ctrl->bs->right = false;
	ctrl->bs->dir = true;
}
