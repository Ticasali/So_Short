/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_animation_button.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:48:28 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 02:32:13 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	menu_animation_button(Control_t *ctrl)
{
	if (ctrl->MeS->xmouse >= 500 && ctrl->MeS->xmouse <= 800
		&& ctrl->MeS->ymouse >= 400 && ctrl->MeS->ymouse <= 550)
	{
		menu_animation_button_incr(ctrl, 0);
		ctrl->MeS->FrameButton[1] = 0;
		ctrl->MeS->FrameButton[2] = 0;
	}
	else if (ctrl->MeS->xmouse >= 500 && ctrl->MeS->xmouse <= 800
		&& ctrl->MeS->ymouse >= 600 && ctrl->MeS->ymouse <= 750)
	{
		menu_animation_button_incr(ctrl, 1);
		ctrl->MeS->FrameButton[0] = 0;
		ctrl->MeS->FrameButton[2] = 0;
	}
	else if (ctrl->MeS->xmouse >= 500 && ctrl->MeS->xmouse <= 800
		&& ctrl->MeS->ymouse >= 800 && ctrl->MeS->ymouse <= 950)
	{
		menu_animation_button_incr(ctrl, 2);
		ctrl->MeS->FrameButton[0] = 0;
		ctrl->MeS->FrameButton[1] = 0;
	}
	else
		menu_animation_button_incr(ctrl, 3);
}

void	menu_animation_button_incr(Control_t *ctrl, int check)
{
	if (check == 0)
	{
		if (ctrl->MeS->FrameButton[0] < 3)
			++ctrl->MeS->FrameButton[0];
		else
			ctrl->MeS->FrameButton[0] = 0;
	}
	else if (check == 1)
	{
		if (ctrl->MeS->FrameButton[1] < 3)
			++ctrl->MeS->FrameButton[1];
		else
			ctrl->MeS->FrameButton[1] = 0;
	}
	else if (check == 2)
	{
		if (ctrl->MeS->FrameButton[2] < 3)
			++ctrl->MeS->FrameButton[2];
		else
			ctrl->MeS->FrameButton[2] = 0;
	}
	else
		menu_animation_button_reset(ctrl);
}

void	menu_animation_button_reset(Control_t *ctrl)
{
	ctrl->MeS->FrameButton[0] = 0;
	ctrl->MeS->FrameButton[1] = 0;
	ctrl->MeS->FrameButton[2] = 0;
}