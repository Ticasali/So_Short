/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_damage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:12 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 16:19:40 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player_damage(t_Control *ctrl)
{
	t_Trspy	dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	if (ctrl->ps->right == true)
	{
		src = load_transparency(ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->ps->x - ctrl->x_dif, ctrl->ps->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
//				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->right == false)
	{
		src = load_transparency(ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->ps->x - ctrl->x_dif, ctrl->ps->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
//				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->xframe < 5)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->yframe = 6;
		ctrl->ps->xframe = 0;
	}
}

void	display_player_death(t_Control *ctrl)
{
	t_Trspy	dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	if (ctrl->ps->right == true)
	{
		src = load_transparency(ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->ps->x - ctrl->x_dif, ctrl->ps->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
//				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->right == false)
	{
		src = load_transparency(ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->ps->x - ctrl->x_dif, ctrl->ps->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
//				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->xframe < 12)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->yframe = 6;
		ctrl->ps->xframe = 0;
	}
}

void	display_player_defend(t_Control *ctrl)
{
	t_Trspy	dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	if (ctrl->ps->right == true)
	{
		src = load_transparency(ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->ps->x - ctrl->x_dif, ctrl->ps->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
//				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->right == false)
	{
		src = load_transparency(ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe], 864, 384);
		put_img_to_img_play(dst, src, ctrl->ps->x - ctrl->x_dif, ctrl->ps->y - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
//				ctrl->ps->x - ctrl->x_dif, ctrl->ps->y- ctrl->y_dif);
	}
	if (ctrl->ps->xframe < 9)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->yframe = 6;
		ctrl->ps->xframe = 0;
	}
}