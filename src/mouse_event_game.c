/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:28:28 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 03:43:25 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	mouse_event_game(int keycode, Control_t *ctrl)
{
	if (keycode == 1)
	{
		if (ctrl->PS->Yframe != 7)
		{
			ctrl->PS->Yframe = 2;
			ctrl->PS->Xframe = 0;
		}
		else
		{
			ctrl->PS->Yframe = 1;
			ctrl->PS->Xframe = 0;
		}
	}
}