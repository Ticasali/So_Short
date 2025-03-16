/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:14:00 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 16:44:06 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	movement(t_Control *ctrl)
{
	movement_player(ctrl);
	movement_enemis(ctrl);
}

void	movement_player(t_Control *ctrl)
{
	if (ctrl->ps->move == true)
	{
		if (ctrl->ps->left == true)
			key_event_game_left(ctrl);
		else if (ctrl->ps->right == true)
			key_event_game_right(ctrl);
		if (ctrl->ps->up == true)
			key_event_game_up(ctrl);
	}
}

void	movement_enemis(t_Control *ctrl)
{
	t_Enemi	*cpy;

	cpy = ctrl->es;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			ia_enemis(ctrl, cpy);
		}
		cpy = cpy->next;
	}
}
