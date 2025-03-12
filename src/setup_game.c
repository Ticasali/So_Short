/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:59:32 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 03:41:53 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	start_game_setup(Control_t *ctrl)
{
	if (check_parsing(ctrl) == false)
		return ; // Turbo Free
	if (ctrl->PS->stat == NULL)
		ctrl->PS->stat = load_stat_struct();
	if (ctrl->PS->stat == NULL)
		return ;
	load_pos_player(ctrl);
	if (load_enemis(ctrl) == false)
		return ; //Turbo Free
	if (load_coin(ctrl) == false)
		return ; //Turbo Free
	mlx_do_key_autorepeatoff(ctrl->WS->ml);
	game(ctrl);
}