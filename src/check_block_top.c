/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:53:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 18:04:56 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	check_block_top(t_Control *ctrl)
{
	t_Block	*cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if ((ctrl->ps->yminh < cpy->ymax)
			&& ((ctrl->ps->xminh >= cpy->xmin
			&& ctrl->ps->xminh < cpy->xmax)
			|| (ctrl->ps->xmaxh > cpy->xmin
			&& ctrl->ps->xmaxh <= cpy->xmax)))
		{
			return (false);
		}
		cpy = cpy->next;
	}
	return (true);
}