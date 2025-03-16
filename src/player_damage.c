/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_damage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:12 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 02:57:03 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player_damage(t_Control *ctrl)
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
	if (ctrl->ps->xframe < 5)
		++ctrl->ps->xframe;
	else
		ctrl->ps->xframe = 0;
}

void	display_player_death(t_Control *ctrl)
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
	if (ctrl->ps->xframe < 12)
		++ctrl->ps->xframe;
	else
		ctrl->ps->xframe = 0;
}

void	display_player_defend(t_Control *ctrl)
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
	if (ctrl->ps->xframe < 9)
		++ctrl->ps->xframe;
	else
		ctrl->ps->xframe = 0;
}