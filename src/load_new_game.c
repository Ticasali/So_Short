/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_new_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:35:04 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/14 12:11:48 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	load_new_game(t_Control *ctrl)
{
	mlx_hook(ctrl->ws->win, 2, 1, keyboard_input, ctrl);
	mlx_loop_hook(ctrl->ws->ml, load_new_game_render, ctrl);
	mlx_loop(ctrl->ws->ml);
	mlx_reset(ctrl->ws->ml);
	mlx_clear_window(ctrl->ws->ml, ctrl->ws->win);;
	start_game_setup(ctrl);
}

int	load_new_game_render(t_Control *ctrl)
{
	double	time;

	time = get_time();
	if ((time - 0.2) > ctrl->mes->time)
	{
		if (ctrl->mes->frameback < 2)
			++ctrl->mes->frameback;
		else
			ctrl->mes->frameback = 0;
		ctrl->mes->time = time;
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			ctrl->mes->background[ctrl->mes->frameback], 0, 0);
		print_string(ctrl, ctrl->login, 200, 400);
	}
	return (0);
}