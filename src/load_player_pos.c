/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:52:08 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 11:16:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	load_pos_player(t_Control *ctrl)
{
	size_t	ct;
	t_Map	*map;
	size_t	ct_y;
	size_t	ct_x;

	ct = -1;
	map = ctrl->ms;
	while (++ct < ctrl->statement)
		map = map->next;
	ct_y = find_player(map->map, true);
	ct_x = find_player(map->map, false);
	ctrl->ps->x = 64 * ct_x - 368;
	ctrl->ps->y = 64 * ct_y - 320;
	ctrl->ps->xminh = 64 * ct_x + 64;
	ctrl->ps->xmaxh = 64 * ct_x + 128;
	ctrl->ps->yminh = 64 * ct_y - 64;
	ctrl->ps->ymaxh = 64 * ct_y + 64;
	ctrl->ps->up = 0;
	ctrl->ps->move = 0;
	ctrl->ps->up_val = 128;
	ctrl->ps->left = false;
	ctrl->ps->right = false;
	ctrl->ps->dir = true;
}
