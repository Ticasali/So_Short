/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:28 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 18:15:33 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_player_idle(t_Control *ctrl)
{
	if (ctrl->ps->right == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->right == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->xframe < 7)
		++ctrl->ps->xframe;
	else
		ctrl->ps->xframe = 0;
}

void	display_player_jump(t_Control *ctrl)
{
	if (ctrl->ps->right == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->right == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->xframe < 19)
		++ctrl->ps->xframe;
	else
	{
		ctrl->ps->yframe = 6;
		ctrl->ps->xframe = 0;
	}
	if (ctrl->ps->xframe < 10)
	{
		//if (check_block_top(ctrl) == true)
	//	{
			ctrl->ps->y -= ctrl->ps->stat->speed * 4 + 1;
			ctrl->ps->yminh -= ctrl->ps->stat->speed * 4 + 1;
			ctrl->ps->ymaxh -= ctrl->ps->stat->speed * 4 + 1;
	//	}
	//	else
	//	{
	//		ctrl->ps->xframe = 11;
	//	}
	}
}

void	display_player_move(t_Control *ctrl)
{
	if (ctrl->ps->right == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgr[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->right == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
				ctrl->ps->imgl[ctrl->ps->yframe][ctrl->ps->xframe],
				ctrl->ps->x, ctrl->ps->y);
	}
	if (ctrl->ps->xframe < 7)
		++ctrl->ps->xframe;
	else
		ctrl->ps->xframe = 0;
}