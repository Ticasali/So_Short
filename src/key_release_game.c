/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:50:19 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 03:19:36 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	key_release_game(int keycode, Control_t *ctrl)
{
	if (keycode == XK_Left)
		ctrl->PS->left = false;
	if (keycode == XK_Right)
		ctrl->PS->right = true;
}