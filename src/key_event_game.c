/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:06:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 02:54:24 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	key_event_game(int keycode, Control_t *ctrl)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(ctrl->WS->ml, ctrl->WS->win);
		return ; //Turbo Free
	}
	if (keycode == XK_Up)
		key_event_game_up(ctrl);
}

void	key_event_game_up(Control_t *ctrl)
{
	if (ctrl->PS->Up == 0)
	{
		if (ctrl->PS->Up == 0)
		{
			ctrl->PS->Up_Val = ctrl->PS->YmaxH - 75;
			ctrl->PS->Up = 1;
		}
		if (ft_move_u(ctrl) == 0)
		{
			ctrl->PS->YminH -= 1;
			ctrl->PS->YmaxH -= 1;
			ctrl->PS->y -= 1;
		}
	}
}