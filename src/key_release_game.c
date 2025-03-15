/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:50:19 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 03:34:23 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	key_release_game(int keycode, t_Control *ctrl)
{
	if (keycode == XK_Left)
		ctrl->ps->left = false;
	if (keycode == XK_Right)
		ctrl->ps->right = true;
	return (0);
}
