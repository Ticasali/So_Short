/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:35:51 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:34 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_coin(t_Control *ctrl)
{
	t_Coin *cpy;
	t_Trspy	dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	cpy = ctrl->cs;
	while (cpy != NULL)
	{
		if (cpy->life == true)
		{
			src = load_transparency(cpy->img[cpy->frame], 64, 64);
			put_img_to_img_play(dst, src, cpy->xmin - ctrl->x_dif, cpy->ymin - ctrl->y_dif);
			mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				cpy->img[cpy->frame],
				cpy->xmin - ctrl->x_dif, cpy->ymin- ctrl->y_dif);
			if (cpy->frame < 6)
				++cpy->frame;
			else
				cpy->frame = 0;
		}
		cpy = cpy->next;
	}
}
