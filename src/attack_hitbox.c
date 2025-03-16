/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_hitbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:52:05 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 17:14:39 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	check_enemis_damage(t_Control *ctrl)
{
	t_Enemi *cpy;

	cpy = ctrl->es;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			check_enemis_hitbox(ctrl, cpy);
		}
		cpy = cpy->next;
	}
}

void	check_enemis_hitbox(t_Control *ctrl, t_Enemi *en)
{
	if (ctrl->ps->dir == true)
	{
		if (((ctrl->ps->xmaxh + 300 > en->xmin)
			&& (ctrl->ps->xmaxh < en->xmin))
			&& ((ctrl->ps->y < en->ymax)
			&& (ctrl->ps->ymaxh + 64 > en->ymin)))
			{
				en->yframe = 2;
				en->life = false;
			}
	}
	else
	{
		if (((ctrl->ps->xminh - 300 < en->xmin)
			&& (ctrl->ps->xmaxh > en->xmin))
			&& ((ctrl->ps->y < en->ymax)
			&& (ctrl->ps->ymaxh + 64 > en->ymin)))
			{
				en->yframe = 2;
				en->life = false;
			}
	}
}