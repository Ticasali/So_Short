/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:45:13 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/18 18:18:11 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_block(t_Control *ctrl)
{
	t_Block *cpy;

	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if (ctrl->paral == false)
			mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win, cpy->img, cpy->xmin - ctrl->x_dif, cpy->ymin - ctrl->y_dif);
		else
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win, cpy->imgp, cpy->xmin - ctrl->x_dif, cpy->ymin- ctrl->y_dif);
		cpy = cpy->next;
	}
}