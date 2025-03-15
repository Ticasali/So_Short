/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:56:58 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 11:19:52 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	game_render(t_Control *ctrl)
{
	double	time;

	time = get_time();
	if ((time - 0.05) > ctrl->mes->time)
	{
		ctrl->mes->time = time;
		if (ft_move_down(ctrl) == 0)
		{
			ctrl->ps->yminh += ctrl->ps->stat->speed * 2;
			ctrl->ps->ymaxh += ctrl->ps->stat->speed * 2;
			ctrl->ps->y += ctrl->ps->stat->speed * 2;
		}
		display_back(ctrl);
		display_coin(ctrl);
		display_player(ctrl);
		display_block(ctrl);
	}
	return (0);
}
//		display_paralax(ctrl);
//		display_enem(ctrl);
//		display_spell(ctrl);
//		display_pnj(ctrl);
//		display_decor(ctrl);