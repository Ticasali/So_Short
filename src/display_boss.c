/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_boss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:11:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:41:13 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_boss(t_Control *ctrl)
{
//	if (ctrl->ps->yframe == 0)
//		display_boss_attack(ctrl);
//	if (ctrl->ps->yframe == 1)
//		display_boss_attack_a(ctrl);
//	if (ctrl->ps->yframe == 2)
//		display_boss_attack_s(ctrl);
//	if (ctrl->ps->yframe == 3)
//		display_boss_damage(ctrl);
//	if (ctrl->ps->yframe == 4)
//		display_boss_death(ctrl);
//	if (ctrl->ps->yframe == 5)
//		display_boss_defend(ctrl);
	if (ctrl->bs->yframe == 6)
		display_boss_idle(ctrl);
//	if (ctrl->bs->yframe == 7)
//		display_boss_jump(ctrl);
	if (ctrl->bs->yframe == 8)
		display_boss_move(ctrl);
}
