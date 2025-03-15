/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:16:51 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 06:33:50 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_back(t_Control *ctrl)
{
	size_t	ct;
	t_Back	*back;

	ct = 0;
	back = ctrl->bas;
	while (ct != ctrl->statement)
	{
		back = back->next;
		++ct;
	}
	mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win, back->img, 0, 0);
}

//Check Transparency