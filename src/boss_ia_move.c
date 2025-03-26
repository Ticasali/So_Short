/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_ia_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:54 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:10:43 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	boss_move_right(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((ctrl->bs->xmaxh + ctrl->bs->stat->speed) >= cpy->xmin)
				&& ((ctrl->bs->xmaxh + ctrl->bs->stat->speed) < cpy->xmax))
			&& ((ctrl->bs->yminh >= cpy->ymin
					&& ctrl->bs->yminh < cpy->ymax)
				|| (ctrl->bs->ymaxh > cpy->ymin
					&& ctrl->bs->ymaxh <= cpy->ymax)))
		{
			ctrl->bs->xmaxh = cpy->xmin;
			ctrl->bs->xminh = ctrl->bs->xmaxh - 128;
			ctrl->bs->x = ctrl->bs->xminh - 368;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}

bool	boss_move_left(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((ctrl->bs->xminh - ctrl->bs->stat->speed) <= cpy->xmax)
				&& ((ctrl->bs->xminh - ctrl->bs->stat->speed) > cpy->xmin))
			&& ((ctrl->bs->yminh >= cpy->ymin
					&& ctrl->bs->yminh < cpy->ymax)
				|| (ctrl->bs->ymaxh > cpy->ymin
					&& ctrl->bs->ymaxh <= cpy->ymax)))
		{
			ctrl->bs->xminh = cpy->xmax;
			ctrl->bs->xmaxh = ctrl->bs->xminh + 128;
			ctrl->bs->x = ctrl->bs->xminh - 368;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}

bool	boss_move_down(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((ctrl->bs->ymaxh + ctrl->bs->stat->speed) >= cpy->ymin)
				&& ((ctrl->bs->ymaxh + ctrl->bs->stat->speed) < cpy->ymax))
			&& ((ctrl->bs->xminh >= cpy->xmin
					&& ctrl->bs->xminh < cpy->xmax)
				|| (ctrl->bs->xmaxh > cpy->xmin
					&& ctrl->bs->xmaxh <= cpy->xmax)))
		{
			ctrl->bs->ymaxh = cpy->ymin;
			ctrl->bs->yminh = ctrl->bs->ymaxh - 128;
			ctrl->bs->y = cpy->ymin - 368 - 10;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}
