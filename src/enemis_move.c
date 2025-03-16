/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemis_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:14:51 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 17:54:56 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	enem_move_down(t_Control *ctrl)
{
	t_Enemi *cpy;

	cpy = ctrl->es;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			if (e_move_down(ctrl, cpy) == 0)
			{
				cpy->ymin += cpy->speed * 2;
				cpy->ymax += cpy->speed * 2;
			}
		}
		cpy = cpy->next;
	}
}

bool	e_move_down(t_Control *ctrl, t_Enemi *en)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((en->ymin + en->speed) >= cpy->ymin)
				&& ((en->ymin + en->speed) < cpy->ymax))
			&& ((en->xmin >= cpy->xmin
					&& en->xmin < cpy->xmax)
				|| (en->xmax > cpy->xmin
					&& en->xmax <= cpy->xmax)))
		{
			en->ymin = cpy->ymin;
			en->ymax = en->ymin - 64;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}

bool	e_move_right(t_Control *ctrl, t_Enemi *en)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((en->xmax + en->speed) >= cpy->xmin)
				&& ((en->xmax + en->speed) < cpy->xmax))
			&& ((en->ymin > cpy->ymin
					&& en->ymin < cpy->ymax)
				|| (en->ymax >= cpy->ymin
					&& en->ymax <= cpy->ymax)))
		{
			en->xmax = cpy->xmin;
			en->xmin = en->xmax - 64;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}

bool	e_move_left(t_Control *ctrl, t_Enemi *en)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((((en->xmin - en->speed) <= cpy->xmax)
				&& ((en->xmin - en->speed) > cpy->xmin))
			&& ((en->ymin > cpy->ymin
					&& en->ymin < cpy->ymax)
				|| (en->ymax >= cpy->ymin
					&& en->ymax <= cpy->ymax)))
		{
			en->xmin = cpy->xmax;
			en->xmax = en->xmin + 64;
			return (true);
		}
		cpy = cpy->next;
	}
	return (false);
}