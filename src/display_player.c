/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:45:24 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 11:54:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player(t_Control *ctrl)
{
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
	if (ctrl->ps->xframe < 17)
		++ctrl->ps->xframe;
	else
		ctrl->ps->xframe = 0;
}