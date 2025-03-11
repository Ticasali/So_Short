/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:31:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 09:06:03 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	game_menu(Control_t *ctrl)
{
	Menu_t	*menu;
	
	menu = load_menu_struct(ctrl->WS);
	if (menu == NULL)
		return ;
	ctrl->MeS = menu;
	while (menu->statement == 0)
	{
		mlx_hook(ctrl->WS->win, 2, 1L<<0, escape_touch, ctrl);
		mlx_mouse_hook(ctrl->WS->win, check_click_menu, ctrl);
		mlx_loop_hook(ctrl->WS->ml, menu_render, ctrl);
		mlx_loop(ctrl->WS->ml);
	}
	mlx_clear_window(ctrl->WS->ml, ctrl->WS->win);
	mlx_loop_end(ctrl->WS->ml);
	if (menu->statement == 1)
		load_new_game(ctrl);
	if (menu->statement == 2)
		load_save_game(ctrl);
	if (menu->statement == 3)
		return ; //Turbo Free
}

void	check_click_menu(int keycode, Control_t *ctrl)
{
	mlx_mouse_get_pos(ctrl->WS->ml, ctrl->WS->win, &ctrl->MeS->xmouse, &ctrl->MeS->ymouse);
	if (keycode == 1)
	{
		if (ctrl->MeS->xmouse >= 500 && ctrl->MeS->xmouse <= 800
			&& ctrl->MeS->ymouse >= 400 && ctrl->MeS->ymouse <= 550)
			ctrl->MeS->statement = 1;
		else if (ctrl->MeS->xmouse >= 500 && ctrl->MeS->xmouse <= 800
			&& ctrl->MeS->ymouse >= 600 && ctrl->MeS->ymouse <= 750)
			ctrl->MeS->statement = 2;
		else if (ctrl->MeS->xmouse >= 500 && ctrl->MeS->xmouse <= 800
			&& ctrl->MeS->ymouse >= 800 && ctrl->MeS->ymouse <= 950)
			ctrl->MeS->statement = 3;
	}
}

void	menu_render(Control_t *ctrl)
{
	double	time;

	mlx_mouse_get_pos(ctrl->WS->ml, ctrl->WS->win, &ctrl->MeS->xmouse, &ctrl->MeS->ymouse);
	time = get_pos();
	if ((time + 0.05) > ctrl->MeS->time)
	{
		if (ctrl->MeS->FrameBack < 3)
			++ctrl->MeS->FrameBack;
		else
			ctrl->MeS->FrameBack = 0;
		menu_animation_button(ctrl);
		ctrl->MeS->time = time;
		mlx_put_image_to_window(ctrl->WS->ml, ctrl->WS->win
			, ctrl->MeS->background[ctrl->MeS->FrameBack], 0, 0);
		mlx_put_image_to_window(ctrl->WS->ml, ctrl->WS->win
			, ctrl->MeS->button[0][ctrl->MeS->FrameButton[0]], 0, 0);
		mlx_put_image_to_window(ctrl->WS->ml, ctrl->WS->win
			, ctrl->MeS->button[1][ctrl->MeS->FrameButton[1]], 0, 0);
		mlx_put_image_to_window(ctrl->WS->ml, ctrl->WS->win
			, ctrl->MeS->button[2][ctrl->MeS->FrameButton[2]], 0, 0);
	}
}

void	escape_touch(int keycode, Control_t *ctrl)
{
	if (keycode == XK_Escape)
		ctrl->MeS->statement = 3;
}