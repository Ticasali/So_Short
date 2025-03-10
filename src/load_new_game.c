/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_new_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:35:04 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 04:53:50 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	load_new_game(Control_t *ctrl)
{
//	mlx_hook(ctrl->WS->win, 2, 1L<<0, keyboard_input, ctrl); Need Proto
	mlx_loop_hook(ctrl->WS->ml, load_new_game_render, ctrl);
	mlx_loop(ctrl->WS->ml);
}

void	load_new_game_render(Control_t *ctrl)
{
	double	time;

	time = get_pos();
	if ((time + 0.05) > ctrl->MeS->time)
	{
		if (ctrl->MeS->FrameBack < 3)
			++ctrl->MeS->FrameBack;
		else
			ctrl->MeS->FrameBack = 0;
		ctrl->MeS->time = time;
		mlx_put_image_to_window(ctrl->WS->ml, ctrl->WS->win
			, ctrl->MeS->background[ctrl->MeS->FrameBack], 0, 0);
		print_string(ctrl, ctrl->login, 200, 400);
	}
}