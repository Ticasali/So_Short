/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:48:53 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/25 16:02:30 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player_attack(t_Control *ctrl)
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
	if (ctrl->ps->xframe < 10)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->xframe = 0;
		ctrl->ps->yframe = 6;
	}
	if (ctrl->ps->xframe == 5)
	{
		check_enemis_damage(ctrl, 150);
	}
}

void	display_player_attack_a(t_Control *ctrl)
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
	if (ctrl->ps->xframe < 7)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->xframe = 13;
		ctrl->ps->yframe = 7;
	}
	if (ctrl->ps->xframe == 4)
	{
		check_enemis_damage(ctrl, 200);
	}
}

void	display_player_attack_s(t_Control *ctrl)
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
	if (ctrl->ps->xframe < 17)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->xframe = 0;
		ctrl->ps->yframe = 6;
	}
	if (ctrl->ps->xframe == 13)
	{
		check_enemis_damage(ctrl, 280);
	}
}