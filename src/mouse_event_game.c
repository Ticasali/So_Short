/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:28:28 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/14 13:05:10 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	mouse_event_game(int keycode, t_Control *ctrl)
{
	if (keycode == 1)
	{
		if (ctrl->ps->yframe != 7)
		{
			ctrl->ps->yframe = 2;
			ctrl->ps->xframe = 0;
		}
		else
		{
			ctrl->ps->yframe = 1;
			ctrl->ps->xframe = 0;
		}
	}
	return (0);
}
