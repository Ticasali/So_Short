/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:56:58 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 22:59:43 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	game_render(Control_t *ctrl)
{
	double	time;
	time = get_pos();
	if ((time + 0.05) > ctrl->MeS->time)
	{
		display_back(ctrl);
//		display_paralax(ctrl);
//		display_block(ctrl);
//		display_player(ctrl);
//		display_enem(ctrl);
//		display_spell(ctrl);
//		display_pnj(ctrl);
//		display_coin(ctrl);
//		display_decor(ctrl);
	}
}