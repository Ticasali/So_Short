/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:45:24 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/19 12:27:25 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player(t_Control *ctrl)
{
	if (ctrl->ps->yframe == 0)
		display_player_attack(ctrl);
	if (ctrl->ps->yframe == 1)
		display_player_attack_a(ctrl);
	if (ctrl->ps->yframe == 2)
		display_player_attack_s(ctrl);
	if (ctrl->ps->yframe == 3)
		display_player_damage(ctrl);
	if (ctrl->ps->yframe == 4)
		display_player_death(ctrl);
	if (ctrl->ps->yframe == 5)
		display_player_defend(ctrl);
	if (ctrl->ps->yframe == 6)
		display_player_idle(ctrl);
	if (ctrl->ps->yframe == 7)
		display_player_jump(ctrl);
	if (ctrl->ps->yframe == 8)
		display_player_move(ctrl);
}



/*
	if (ctrl->ps->right == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->right == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->xframe < 7)
		++ctrl->ps->xframe;
	else
		ctrl->ps->xframe = 0;
*/
