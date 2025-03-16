/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:59:54 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 16:50:08 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	gravity(t_Control *ctrl)
{
	if (ft_move_down(ctrl) == 0)
	{
		ctrl->ps->yminh += ctrl->ps->stat->speed * 2;
		ctrl->ps->ymaxh += ctrl->ps->stat->speed * 2;
		ctrl->ps->y += ctrl->ps->stat->speed * 2;
	}
	enem_move_down(ctrl);
}