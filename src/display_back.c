/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:16:51 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 22:58:29 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_back(Control_t *ctrl)
{
	size_t	ct;
	Back_t	*back;

	ct = 0;
	while (ct != ctrl->Statement)
	{
		back = back->next;
		++ct;
	}
	mlx_put_image_to_window(ctrl->WS->ml, ctrl->WS->win, back->img, 0, 0);
}

//Check Transparency