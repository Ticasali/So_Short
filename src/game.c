/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 05:54:43 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 12:04:31 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	game(t_Control *ctrl)
{
	mlx_key_hook(ctrl->ws->win, key_event_game, ctrl);
//	mlx_mouse_hook(ctrl->ws->win, mouse_event_game, ctrl);
//	mlx_hook(ctrl->ws->ml, KeyPress, KeyPressMask, key_pressed_game, ctrl);
//	mlx_hook(ctrl->ws->ml, KeyRelease, KeyReleaseMask, key_release_game, ctrl);
	mlx_loop_hook(ctrl->ws->ml, game_render, ctrl);
	mlx_loop(ctrl->ws->ml);
}
