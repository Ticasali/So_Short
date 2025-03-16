/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:49:26 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 17:37:32 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	key_pressed_game(int keycode, t_Control *ctrl)
{
	if (keycode == XK_Escape)
	{
		mlx_do_key_autorepeaton(ctrl->ws->ml);
		mlx_destroy_window(ctrl->ws->ml, ctrl->ws->win);
		return (-1);
	}
	if (ctrl->ps->yframe != 2)
	{
		if (keycode == XK_Left || keycode == XK_Right)
		{
			if (ctrl->ps->yframe == 6)
			{
				ctrl->ps->xframe = 0;
				ctrl->ps->yframe = 8;
			}
			if (ctrl->ps->yframe != 0 && ctrl->ps->yframe != 2)
			{
				if (keycode == XK_Left)
				{
					ctrl->ps->move = true;
					ctrl->ps->dir = false;
					ctrl->ps->left = true;
					if (ctrl->ps->right == true)
						ctrl->ps->right = false;
				}
				else if (keycode == XK_Right)
				{
					ctrl->ps->move = true;
					ctrl->ps->dir = true;
					ctrl->ps->right = true;
					if (ctrl->ps->left == true)
						ctrl->ps->left = false;
				}
			}
		}
		if (keycode == XK_Up)
		{
			ctrl->ps->up = 1;
			ctrl->ps->xframe = 0;
			ctrl->ps->yframe = 7;
		}
	}
	return (0);
}
