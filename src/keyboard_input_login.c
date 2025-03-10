/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input_login.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:47:03 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 05:01:37 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	keyboard_input(int keycode, Control_t *ctrl)
{
	if (keycode == XK_Delete)
		del_char_login(ctrl);
	if (keycode == XK_Escape)
		return ; // turbo free
	if (keycode == XK_a)
		add_char_login(ctrl, 'a');
	if (keycode == XK_b)
		add_char_login(ctrl, 'b');
	if (keycode == XK_c)
		add_char_login(ctrl, 'c');
	if (keycode == XK_d)
		add_char_login(ctrl, 'd');
	if (keycode == XK_e)
		add_char_login(ctrl, 'e');
	if (keycode == XK_f)
		add_char_login(ctrl, 'f');
	if (keycode == XK_g)
		add_char_login(ctrl, 'g');
	if (keycode == XK_h)
		add_char_login(ctrl, 'h');
	if (keycode == XK_i)
		add_char_login(ctrl, 'i');
	if (keycode == XK_j)
		add_char_login(ctrl, 'j');
	keyboard_input_two(keycode, ctrl);
}

void	keyboard_input_two(int keycode, Control_t *ctrl)
{
	if (keycode == XK_k)
		add_char_login(ctrl, 'k');
	if (keycode == XK_l)
		add_char_login(ctrl, 'l');
	if (keycode == XK_m)
		add_char_login(ctrl, 'm');
	if (keycode == XK_n)
		add_char_login(ctrl, 'n');
	if (keycode == XK_o)
		add_char_login(ctrl, 'o');
	if (keycode == XK_p)
		add_char_login(ctrl, 'p');
	if (keycode == XK_q)
		add_char_login(ctrl, 'q');
	if (keycode == XK_r)
		add_char_login(ctrl, 'r');
	if (keycode == XK_s)
		add_char_login(ctrl, 's');
	if (keycode == XK_t)
		add_char_login(ctrl, 't');
	if (keycode == XK_u)
		add_char_login(ctrl, 'u');
	keyboard_input_three(keycode, ctrl);
}

void	keyboard_input_three(int keycode, Control_t *ctrl)
{
	if (keycode == XK_v)
		add_char_login(ctrl, 'v');
	if (keycode == XK_w)
		add_char_login(ctrl, 'w');
	if (keycode == XK_x)
		add_char_login(ctrl, 'x');
	if (keycode == XK_y)
		add_char_login(ctrl, 'y');
	if (keycode == XK_z)
		add_char_login(ctrl, 'z');
	if (keycode == XK_p)
		add_char_login(ctrl, 'p');
	if (keycode == XK_Return)
	{
		if (check_login(ctrl) == true)
		{
			mlx_loop_end(ctrl->WS->ml);
			mlx_clear_window(ctrl->WS->ml, ctrl->WS->win);
			start_game_setup(ctrl);
		}
		else
			bad_login_render(ctrl); //A faire
	}
}
