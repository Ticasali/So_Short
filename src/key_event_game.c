/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:06:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 12:01:06 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	key_event_game(int keycode, t_Control *ctrl)
{
	if (keycode == XK_Escape)
	{
		mlx_do_key_autorepeaton(ctrl->ws->ml);
		mlx_destroy_window(ctrl->ws->ml, ctrl->ws->win);
		return (-1);
	}
	if (keycode == XK_Up)
		key_event_game_up(ctrl);
	if (keycode == XK_Right)
	{
		ctrl->ps->right = true;
		key_event_game_right(ctrl);
	}
	if (keycode == XK_Left)
	{
		ctrl->ps->right = false;
		key_event_game_left(ctrl);
	}
	return (0);
}

void	key_event_game_up(t_Control *ctrl)
{
	if (ctrl->ps->up == 0)
	{
		if (ctrl->ps->up == 0)
		{
			ctrl->ps->up_val = ctrl->ps->ymaxh - 75;
			ctrl->ps->up = 1;
		}
		if (ft_move_up(ctrl) == 0)
		{
			ctrl->ps->yminh -= 1;
			ctrl->ps->ymaxh -= 1;
			ctrl->ps->y -= 1;
		}
	}
}

void	key_event_game_right(t_Control *ctrl)
{
	if (ft_move_right(ctrl) == 0)
	{
		ctrl->ps->xminh += ctrl->ps->stat->speed;
		ctrl->ps->xmaxh += ctrl->ps->stat->speed;
		ctrl->ps->x += ctrl->ps->stat->speed;
	}
}

void	key_event_game_left(t_Control *ctrl)
{
	if (ft_move_left(ctrl) == 0)
	{
		ctrl->ps->xminh -= ctrl->ps->stat->speed;
		ctrl->ps->xmaxh -= ctrl->ps->stat->speed;
		ctrl->ps->x -= ctrl->ps->stat->speed;
	}
}