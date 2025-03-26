/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:59:32 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:52:51 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	start_game_setup(t_Control *ctrl)
{
	if (check_parsing(ctrl) == false)
		return ;
	if (ctrl->statement == 0)
		ctrl->ps->stat = load_stat();
	if (ctrl->ps->stat == NULL)
		return ;
	if (ctrl->statement == 0)
		ctrl->bs->stat = load_stat_boss();
	if (ctrl->bs->stat == NULL)
		return ;
	load_pos_player(ctrl);
	load_pos_boss(ctrl);
	load_block_struct(ctrl);
	if (load_enemis_struct(ctrl) == false)
		return ;
	if (load_coin_struct(ctrl) == false)
		return ;
	mlx_do_key_autorepeatoff(ctrl->ws->ml);
	game(ctrl);
}
