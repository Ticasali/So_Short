/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:29:40 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 11:50:44 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	ft_move_right(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((ctrl->ps->xmaxh + ctrl->ps->stat->speed) >= cpy->xmin)
				&& ((ctrl->ps->xmaxh + ctrl->ps->stat->speed) < cpy->xmax))
			&& ((ctrl->ps->yminh >= cpy->ymin
					&& ctrl->ps->yminh < cpy->ymax)
				|| (ctrl->ps->ymaxh > cpy->ymin
					&& ctrl->ps->ymaxh <= cpy->ymax)))
		{
			ctrl->ps->xmaxh = cpy->xmin;
			ctrl->ps->xminh = ctrl->ps->xmaxh - 32;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}

bool	ft_move_left(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((ctrl->ps->xminh - ctrl->ps->stat->speed) <= cpy->xmax)
				&& ((ctrl->ps->xminh - ctrl->ps->stat->speed) > cpy->xmin))
			&& ((ctrl->ps->yminh >= cpy->ymin
					&& ctrl->ps->yminh < cpy->ymax)
				|| (ctrl->ps->ymaxh > cpy->ymin
					&& ctrl->ps->ymaxh <= cpy->ymax)))
		{
			ctrl->ps->xminh = cpy->xmax;
			ctrl->ps->xmaxh = ctrl->ps->xminh + 32;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}

bool	ft_move_up(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((ctrl->ps->yminh - ctrl->ps->stat->speed) <= cpy->ymax)
				&& ((ctrl->ps->yminh - ctrl->ps->stat->speed) > cpy->ymin))
			&& ((ctrl->ps->xminh >= cpy->xmin
					&& ctrl->ps->xminh < cpy->xmax)
				|| (ctrl->ps->xmaxh > cpy->xmin
					&& ctrl->ps->xmaxh <= cpy->xmax)))
		{
			ctrl->ps->yminh = cpy->ymax;
			ctrl->ps->ymaxh = ctrl->ps->yminh + 32;
			ctrl->ps->up = -1;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}

bool	ft_move_down(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((ctrl->ps->ymaxh + ctrl->ps->stat->speed) >= cpy->ymin)
				&& ((ctrl->ps->ymaxh + ctrl->ps->stat->speed) < cpy->ymax))
			&& ((ctrl->ps->xminh >= cpy->xmin
					&& ctrl->ps->xminh < cpy->xmax)
				|| (ctrl->ps->xmaxh > cpy->xmin
					&& ctrl->ps->xmaxh <= cpy->xmax)))
		{
			ctrl->ps->ymaxh = cpy->ymin;
			ctrl->ps->yminh = ctrl->ps->ymaxh - 32;
			ctrl->ps->y = cpy->ymin - 368 - 10;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}
