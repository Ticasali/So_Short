/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:49:26 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 03:34:09 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	key_pressed_game(int keycode, t_Control *ctrl)
{
	if (keycode == XK_Left)
	{
		ctrl->ps->dir = false;
		ctrl->ps->left = true;
		if (ctrl->ps->right == true)
			ctrl->ps->right = false;
	}
	else if (keycode == XK_Right)
	{
		ctrl->ps->dir = true;
		ctrl->ps->right = true;
		if (ctrl->ps->left == true)
			ctrl->ps->left = false;
	}
	return (0);
}
