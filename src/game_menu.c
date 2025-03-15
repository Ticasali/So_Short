/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:31:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/14 12:10:11 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"
#include "../mlx_linux/mlx_int.h"

void	game_menu(t_Control *ctrl)
{
	t_Menu	*menu;

	menu = load_menu_struct(ctrl->ws);
	if (menu == NULL)
		return ;
	ctrl->mes = menu;
	ctrl->mes->try = 0;
	mlx_hook(ctrl->ws->win, 2, 1L<<0, escape_touch, ctrl);
	mlx_hook(ctrl->ws->win, ButtonPress, ButtonPressMask, check_click_menu, ctrl);
	mlx_loop_hook(ctrl->ws->ml, menu_render, ctrl);
	mlx_loop(ctrl->ws->ml);
	if (menu->statement == 1)
	{
		mlx_reset(ctrl->ws->ml);
		mlx_clear_window(ctrl->ws->ml, ctrl->ws->win);
		load_new_game(ctrl);
	}
//	if (menu->statement == 2)
//		load_save_game(ctrl);
	if (menu->statement == 3)
		return ;
}

int	check_click_menu(int button, int x, int y, t_Control *ctrl)
{
	if (button == 1)
	{
		if ((x >= 500 && x <= 600) && (y >= 150 && y <= 200))
			ctrl->mes->statement = 1;
		if ((x >= 500 && x <= 600) && (y >= 250 && y <= 300))
			ctrl->mes->statement = 2;
		if ((x >= 500 && x <= 600) && (y >= 350 && y <= 400))
			ctrl->mes->statement = 3;
	}
	return (0);
}

int	menu_render(t_Control *ctrl)
{
	double	time;
	double	test;

	time = get_time();
	test = 0.2;
	if ((time - test) > ctrl->mes->time)
	{
		mlx_mouse_get_pos(ctrl->ws->ml, ctrl->ws->win,
			&ctrl->mes->xmouse, &ctrl->mes->ymouse);
		menu_animation_button(ctrl);
		ctrl->mes->time = time;
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			ctrl->mes->background[ctrl->mes->frameback], 0, 0);
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			ctrl->mes->button[0][ctrl->mes->framebutton[0]], 500, 150);
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			ctrl->mes->button[1][ctrl->mes->framebutton[1]], 500, 250);
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			ctrl->mes->button[2][ctrl->mes->framebutton[2]], 500, 350);
		if (ctrl->mes->frameback < 2)
			++ctrl->mes->frameback;
		else
			ctrl->mes->frameback = 0;
	}
	if (ctrl->mes->statement == 3 || ctrl->mes->statement == 1)
		mlx_loop_end(ctrl->ws->ml);	
	return (0);
}

int	escape_touch(int keycode, t_Control *ctrl)
{
	if (keycode == XK_Escape)
	{
		ctrl->mes->statement = 3;
	}
	return (0);
}
