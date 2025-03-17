/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_click_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:36:21 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/17 22:16:42 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	button_click(int button, int x, int y, t_Control *ctrl)
{
	(void)(x);
	(void)(y);
	if (button == 1 && ctrl->ps->yframe == 7)
	{
		ctrl->ps->yframe = 1;
		ctrl->ps->xframe = 0;
		ctrl->ps->move = false;
	}
	else if (button == 1)
	{
		ctrl->ps->xframe = 0;
		ctrl->ps->yframe = 0;
		ctrl->ps->move = false;
	}
	if (button == 3)
	{
		ctrl->ps->xframe = 0;
		ctrl->ps->yframe = 2;
		ctrl->ps->move = false;
	}
	return (0);
}