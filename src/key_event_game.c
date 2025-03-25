/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:06:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 18:24:23 by ticasali         ###   ########.fr       */
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
			ctrl->ps->yminh -= ctrl->ps->stat->speed;
			ctrl->ps->ymaxh -= ctrl->ps->stat->speed;
			ctrl->ps->y -= ctrl->ps->stat->speed;
		}
	}
	hitbox_coin_right(ctrl);
	hitbox_coin_left(ctrl);
}

void	key_event_game_right(t_Control *ctrl)
{
	if (ft_move_right(ctrl) == 0)
	{
		ctrl->ps->xminh += ctrl->ps->stat->speed;
		ctrl->ps->xmaxh += ctrl->ps->stat->speed;
		ctrl->ps->x += ctrl->ps->stat->speed;
	}
	hitbox_coin_right(ctrl);
}

void	key_event_game_left(t_Control *ctrl)
{
	if (ft_move_left(ctrl) == 0)
	{
		ctrl->ps->xminh -= ctrl->ps->stat->speed;
		ctrl->ps->xmaxh -= ctrl->ps->stat->speed;
		ctrl->ps->x -= ctrl->ps->stat->speed;
	}
	hitbox_coin_left(ctrl);
}