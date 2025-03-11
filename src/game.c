/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 05:54:43 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 11:18:00 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	game(Control_t *ctrl)
{
	mlx_key_hook(ctrl->WS->win, input_key_game, ctrl);
	mlx_mouse_hook(ctrl->WS->win,  input_mouse_game, ctrl);
	mlx_loop_hook(ctrl->WS->ml, game_render, ctrl);
	mlx_loop(ctrl->WS->ml);
}

void	input_key_game(); // .h
void	input_mouse_game(); // .h
void	game_render(); //.h