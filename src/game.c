/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 05:54:43 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 05:55:46 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	game(Control_t *ctrl)
{
	mlx_key_hook(ctrl->WS->win, key_event_game, ctrl);
	mlx_mouse_hook(ctrl->WS->win,  mouse_event_game, ctrl);
	mlx_hook(ctrl->WS->ml, KeyPress, KeyPressMask, key_press_event, ctrl);
	mlx_hook(ctrl->WS->ml, KeyRelease, KeyReleaseMask, key_release_event, ctrl);
	mlx_loop_hook(ctrl->WS->ml, game_render, ctrl);
	mlx_loop(ctrl->WS->ml);
}

void	key_event_game(); // .h
void	mouse_event_game(); // .h
void	game_render(); //.h
void	key_press_event(); //.h
void	key_release_event(); //.h