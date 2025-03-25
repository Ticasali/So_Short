/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:28 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 18:32:02 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player_idle(t_Control *ctrl)
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
		ctrl->ps->xframe = 0;
}

void	display_player_jump(t_Control *ctrl)
{
	t_Trspy	dst;
	t_Trspy src;
	bool	check;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	check = false;
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
	if (ctrl->ps->xframe < 19)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->yframe = 6;
		ctrl->ps->xframe = 0;
		check = true;
	}
	if (ctrl->ps->xframe < 10 && check == false)
	{
		hitbox_coin_up(ctrl);
		if (ft_move_up(ctrl) == false)
		{
			ctrl->ps->y -= ctrl->ps->stat->speed * 4 + 1;
			ctrl->ps->yminh -= ctrl->ps->stat->speed * 4 + 1;
			ctrl->ps->ymaxh -= ctrl->ps->stat->speed * 4 + 1;
		}
		else
		{
			ctrl->ps->xframe = 0;
			ctrl->ps->yframe = 6;
		}
	}
}

void	display_player_move(t_Control *ctrl)
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
		ctrl->ps->xframe = 0;
}