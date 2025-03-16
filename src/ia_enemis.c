/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_enemis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 07:02:44 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 16:52:02 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	ia_enemis(t_Control *ctrl, t_Enemi *en)
{
	int	x_player;
	int	x_enem;

	x_player = ctrl->ps->xmaxh - 64;
	x_enem = en->xmax - 32;
	if (x_enem > x_player)
	{
		en->dir = false;
//		en->yframe = 3;
		if (e_move_left(ctrl, en) == false)
		{
			en->xmax -= en->speed;
			en->xmin -= en->speed;
		}
	}
	else
	{
		en->dir = true;
//		en->yframe = 3;
		if (e_move_right(ctrl, en) == false)
		{
			en->xmax += en->speed;
			en->xmin += en->speed;
		}
	}
}