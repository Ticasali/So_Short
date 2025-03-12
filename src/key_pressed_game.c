/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:49:26 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 03:27:29 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	key_pressed_game(int keycode, Control_t *ctrl)
{
	if (keycode == XK_Left)
	{
		ctrl->PS->Dir = false;
		ctrl->PS->left = true;
		if (ctrl->PS->right == true)
			ctrl->PS->right = false;
	}
	else if (keycode == XK_Right)
	{
		ctrl->PS->Dir = true;
		ctrl->PS->right = true;
		if (ctrl->PS->left == true)
			ctrl->PS->left = false;
	}
}