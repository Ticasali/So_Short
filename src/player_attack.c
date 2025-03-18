/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:48:53 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/18 18:18:53 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player_attack(t_Control *ctrl)
{
	if (ctrl->ps->right == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->right == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->xframe < 10)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->xframe = 0;
		ctrl->ps->yframe = 6;
	}
}

void	display_player_attack_a(t_Control *ctrl)
{
	if (ctrl->ps->right == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->right == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->xframe < 7)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->xframe = 13;
		ctrl->ps->yframe = 7;
	}
}

void	display_player_attack_s(t_Control *ctrl)
{
	if (ctrl->ps->right == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->right == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->xframe < 17)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->xframe = 0;
		ctrl->ps->yframe = 6;
	}
	if (ctrl->ps->xframe > 12 && ctrl->ps->xframe < 15)
	{
		check_enemis_damage(ctrl);
	}
}