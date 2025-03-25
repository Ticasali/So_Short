/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:47:12 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 10:14:14 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_enemis(t_Control *ctrl)
{
	t_Enemi *cpy;

	cpy = ctrl->es;
	while (cpy != NULL)
	{
		if (cpy->yframe == 0)
			display_en_attack(ctrl, cpy);
		if (cpy->yframe == 1)
			display_en_damage(ctrl, cpy);
		if (cpy->yframe == 2)
			display_en_death(ctrl, cpy);
		if (cpy->yframe == 3)
			display_en_move(ctrl, cpy);
		cpy = cpy->next;
	}
}

void	display_en_attack(t_Control *ctrl, t_Enemi *cpy)
{
	if (cpy->dir == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			cpy->imgl[cpy->yframe][cpy->xframe],
			cpy->xmin - ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 5)
			++cpy->xframe;
		else
			cpy->xframe = 0;
	}
	if (cpy->dir == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			cpy->imgr[cpy->yframe][cpy->xframe],
			cpy->xmin - ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 5)
			++cpy->xframe;
		else
			cpy->xframe = 0;
	}
}

void	display_en_damage(t_Control *ctrl, t_Enemi *cpy)
{
	if (cpy->dir == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			cpy->imgl[cpy->yframe][cpy->xframe],
			cpy->xmin - ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 4)
			++cpy->xframe;
		else
			cpy->xframe = 0;
	}
	if (cpy->dir == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			cpy->imgr[cpy->yframe][cpy->xframe],
			cpy->xmin- ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 4)
			++cpy->xframe;
		else
			cpy->xframe = 0;
	}
}

void	display_en_death(t_Control *ctrl, t_Enemi *cpy)
{
	if (cpy->dir == false)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			cpy->imgl[cpy->yframe][cpy->xframe],
			cpy->xmin - ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 5)
			++cpy->xframe;
		else
		{
			cpy->life = false;
		}
	}
	if (cpy->dir == true)
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			cpy->imgr[cpy->yframe][cpy->xframe],
			cpy->xmin - ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 5)
			++cpy->xframe;
		else
		{
			cpy->life = false;
		}
	}
}

void	display_en_move(t_Control *ctrl, t_Enemi *cpy)
{
	t_Trspy dst;
	t_Trspy src;

	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	if (cpy->dir == false)
	{
		src = load_transparency(cpy->imgl[cpy->yframe][cpy->xframe], 64, 64);
		put_img_to_img(dst, src, cpy->xmin - ctrl->x_dif, cpy->ymax - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//			cpy->imgl[cpy->yframe][cpy->xframe],
//			cpy->xmin - ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 4)
			++cpy->xframe;
		else
			cpy->xframe = 0;
	}
	if (cpy->dir == true)
	{
		src = load_transparency(cpy->imgr[cpy->yframe][cpy->xframe], 64, 64);
		put_img_to_img(dst, src, cpy->xmin - ctrl->x_dif, cpy->ymax - ctrl->y_dif);
//		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
//			cpy->imgr[cpy->yframe][cpy->xframe],
//			cpy->xmin - ctrl->x_dif, cpy->ymax- ctrl->y_dif);
		if (cpy->xframe < 4)
			++cpy->xframe;
		else
			cpy->xframe = 0;
	}
}
