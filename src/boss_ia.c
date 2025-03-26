/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_ia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:44 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:47:00 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	ia_boss(t_Control *ctrl)
{
	int	x_player;
	int	x_boss;

	x_player = ctrl->ps->xmaxh - 64;
	x_boss = ctrl->bs->xmaxh - 64;
	if (x_boss > x_player)
	{
		ctrl->bs->left = true;
		ctrl->bs->right = false;
		if (boss_move_left(ctrl) == false)
		{
			ctrl->bs->xmaxh -= ctrl->bs->stat->speed;
			ctrl->bs->xminh -= ctrl->bs->stat->speed;
			ctrl->bs->x -= ctrl->bs->stat->speed;
		}
	}
	else
	{
		ctrl->bs->left = false;
		ctrl->bs->right = true;
		if (boss_move_right(ctrl) == false)
		{
			ctrl->bs->xmaxh += ctrl->bs->stat->speed;
			ctrl->bs->xminh += ctrl->bs->stat->speed;
			ctrl->bs->x += ctrl->bs->stat->speed;
		}
	}
}