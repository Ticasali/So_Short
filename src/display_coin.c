/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:35:51 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 10:06:26 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_coin(t_Control *ctrl)
{
	t_Coin *cpy;

	cpy = ctrl->cs;
	while (cpy != NULL)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			cpy->img[cpy->frame],
			cpy->xmin, cpy->ymin);
		if (cpy->frame < 6)
			++cpy->frame;
		else
			cpy->frame = 0;
		cpy = cpy->next;
	}
}