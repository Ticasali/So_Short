/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:14:04 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:09:29 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_boss_idle(t_Control *ctrl)
{
	t_Trspy	dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	if (ctrl->bs->right == true)
	{
		src = load_transparency(ctrl->bs->imgr[ctrl->bs->yframe][ctrl->bs->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->bs->x - ctrl->x_dif, ctrl->bs->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->bs->imgr[ctrl->bs->yframe][ctrl->bs->xframe],
//				ctrl->bs->x - ctrl->x_dif, ctrl->bs->y- ctrl->y_dif);
	}
	if (ctrl->bs->right == false)
	{
		src = load_transparency(ctrl->bs->imgl[ctrl->bs->yframe][ctrl->bs->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->bs->x - ctrl->x_dif, ctrl->bs->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->bs->imgl[ctrl->bs->yframe][ctrl->bs->xframe],
//				ctrl->bs->x - ctrl->x_dif, ctrl->bs->y- ctrl->y_dif);
	}
	if (ctrl->bs->xframe < 7)
		++ctrl->bs->xframe;
	else
		ctrl->bs->xframe = 0;
}

void	display_boss_move(t_Control *ctrl)
{
	t_Trspy	dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	if (ctrl->bs->right == true)
	{
		src = load_transparency(ctrl->bs->imgr[ctrl->bs->yframe][ctrl->bs->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->bs->x - ctrl->x_dif, ctrl->bs->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->bs->imgr[ctrl->bs->yframe][ctrl->bs->xframe],
//				ctrl->bs->x - ctrl->x_dif, ctrl->bs->y- ctrl->y_dif);
	}
	if (ctrl->bs->right == false)
	{
		src = load_transparency(ctrl->bs->imgl[ctrl->bs->yframe][ctrl->bs->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->bs->x - ctrl->x_dif, ctrl->bs->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->bs->imgl[ctrl->bs->yframe][ctrl->bs->xframe],
//				ctrl->bs->x - ctrl->x_dif, ctrl->bs->y- ctrl->y_dif);
	}
	if (ctrl->bs->xframe < 7)
		++ctrl->bs->xframe;
	else
		ctrl->bs->xframe = 0;
}