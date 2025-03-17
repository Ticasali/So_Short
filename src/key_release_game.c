/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:50:19 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/17 22:10:09 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	key_release_game(int keycode, t_Control *ctrl)
{
	if (keycode == XK_Down)
	{
		if (ctrl->paral == false)
			ctrl->paral = true;
		else if (ctrl->paral == true)
			ctrl->paral = false;
	}
	if (ctrl->ps->yframe != 2 && ctrl->ps->yframe != 0)
	{
		if (keycode == XK_Left)
		{
			if (ctrl->ps->yframe != 7)
				ctrl->ps->yframe = 6;
			ctrl->ps->move = false;
			ctrl->ps->left = false;
		}
		if (keycode == XK_Right)
		{
			if (ctrl->ps->yframe != 7)
				ctrl->ps->yframe = 6;
			ctrl->ps->move = false;
			ctrl->ps->right = true;
		}
	}
	return (0);
}
