/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:59:32 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 05:08:17 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	start_game_setup(t_Control *ctrl)
{
	if (check_parsing(ctrl) == false)
	{
		printf("BITE");
		return ;
	}
	if (ctrl->statement == 0)
		ctrl->ps->stat = load_stat();
	if (ctrl->ps->stat == NULL)
		return ;
	load_pos_player(ctrl);
	load_block_struct(ctrl);
	if (load_enemis_struct(ctrl) == false)
	{
		printf("COUILLE");
		return ;
	}
	if (load_coin_struct(ctrl) == false)
		return ;
	mlx_do_key_autorepeatoff(ctrl->ws->ml);
	game(ctrl);
}
