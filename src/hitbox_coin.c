/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:47:11 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 18:22:34 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	hitbox_coin_right(t_Control *ctrl)
{
	t_Coin	*cpy;

	cpy = ctrl->cs;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			if ((((ctrl->ps->xmaxh + ctrl->ps->stat->speed) >= cpy->xmin)
					&& ((ctrl->ps->xmaxh + ctrl->ps->stat->speed) < cpy->xmax))
				&& ((ctrl->ps->yminh >= cpy->ymin
						&& ctrl->ps->yminh < cpy->ymax)
					|| (ctrl->ps->ymaxh > cpy->ymin
						&& ctrl->ps->ymaxh <= cpy->ymax)))
			{
				cpy->life = false;
				if (ctrl->paral == false)
					ctrl->paral = true;
				else
					ctrl->paral = false;
			}
		}
		cpy = cpy->next;
	}
}

void	hitbox_coin_left(t_Control *ctrl)
{
	t_Coin	*cpy;

	cpy = ctrl->cs;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			if ((((ctrl->ps->xminh - ctrl->ps->stat->speed) <= cpy->xmax)
					&& ((ctrl->ps->xminh - ctrl->ps->stat->speed) > cpy->xmin))
				&& ((ctrl->ps->yminh >= cpy->ymin
						&& ctrl->ps->yminh < cpy->ymax)
					|| (ctrl->ps->ymaxh > cpy->ymin
						&& ctrl->ps->ymaxh <= cpy->ymax)))
			{
				cpy->life = false;
				if (ctrl->paral == false)
					ctrl->paral = true;
				else
					ctrl->paral = false;
			}
		}
		cpy = cpy->next;
	}
}

void	hitbox_coin_up(t_Control *ctrl)
{
	t_Coin	*cpy;

	cpy = ctrl->cs;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			if ((((ctrl->ps->yminh - (ctrl->ps->stat->speed * 4)) <= cpy->ymax)
					&& ((ctrl->ps->yminh - (ctrl->ps->stat->speed * 4)) > cpy->ymin))
				&& ((ctrl->ps->xminh >= cpy->xmin
						&& ctrl->ps->xminh < cpy->xmax)
					|| (ctrl->ps->xmaxh > cpy->xmin
						&& ctrl->ps->xmaxh <= cpy->xmax)))
			{
				cpy->life = false;
				if (ctrl->paral == false)
					ctrl->paral = true;
				else
					ctrl->paral = false;
			}
		}
		cpy = cpy->next;
	}
}

void	hitbox_coin_down(t_Control *ctrl)
{
	t_Coin	*cpy;

	cpy = ctrl->cs;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			if ((((ctrl->ps->ymaxh + ctrl->ps->stat->speed) >= cpy->ymin)
					&& ((ctrl->ps->ymaxh + ctrl->ps->stat->speed) < cpy->ymax))
				&& ((ctrl->ps->xminh >= cpy->xmin
						&& ctrl->ps->xminh < cpy->xmax)
					|| (ctrl->ps->xmaxh > cpy->xmin
						&& ctrl->ps->xmaxh <= cpy->xmax)))
			{
				cpy->life = false;
				if (ctrl->paral == false)
					ctrl->paral = true;
				else
					ctrl->paral = false;
			}
		}
		cpy = cpy->next;
	}
}
