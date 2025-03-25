/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:45:13 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 13:17:33 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_block(t_Control *ctrl)
{
	t_Block *cpy;
	t_Trspy	dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	cpy = ctrl->bls;
	while (cpy != NULL)
	{
		if (ctrl->paral == false)
			src = load_transparency(cpy->img, 64, 64);
		else
			src = load_transparency(cpy->imgp, 64, 64);
		put_img_to_img(dst, src, cpy->xmin - ctrl->x_dif, cpy->ymin - ctrl->y_dif);
//		if (ctrl->paral == false)
//			mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win, cpy->img, cpy->xmin - ctrl->x_dif, cpy->ymin - ctrl->y_dif);
//		else
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win, cpy->imgp, cpy->xmin - ctrl->x_dif, cpy->ymin- ctrl->y_dif);
		cpy = cpy->next;
	}
}
