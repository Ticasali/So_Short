/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:56:58 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/18 18:01:51 by ticasali         ###   ########.fr       */
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
		load_scroll(ctrl);
		gravity(ctrl);
		movement(ctrl);
		display_back(ctrl);
		display_player(ctrl);
		display_coin(ctrl);
		display_enemis(ctrl);
		display_block(ctrl);
	}
	return (0);
}
//		display_paralax(ctrl);
//		display_spell(ctrl);
//		display_pnj(ctrl);
//		display_decor(ctrl);