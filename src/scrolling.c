/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:02:05 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/18 21:21:07 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	load_scroll(t_Control *ctrl)
{
	t_Map	*map;
	size_t	ct;

	ct = 0;
	map = ctrl->ms;
	while (ct != ctrl->statement)
		map = map->next;
	if (map->x * 64 >= 3074)
	{
		if (ctrl->ps->xminh >= 1500)
			ctrl->x_dif = ctrl->ps->xminh - 1500;
		else
			ctrl->x_dif = 0;
		if (ctrl->ps->xminh + 1500 > (map->x * 64) - 74)
			ctrl->x_dif = (map->x * 64) - 3074;
	}
	if (map->y * 64 >= 1800)
	{
		if (ctrl->ps->yminh >= 900)
			ctrl->y_dif = ctrl->ps->yminh - 900;
		else
			ctrl->y_dif = 0;
		if (ctrl->ps->yminh + 900 > (map->y * 64) + 64)
			ctrl->y_dif = (map->y * 64) - 1728;
	}
}