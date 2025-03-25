/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:16:51 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/25 16:31:55 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	display_back(t_Control *ctrl)
{
	size_t	ct;
	t_Back	*back;
//	t_Trspy	dst;
//	t_Trspy src;

	ct = 0;
	back = ctrl->bas;
	while (ct != ctrl->statement)
	{
		back = back->next;
		++ct;
	}
	mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win, back->img, 0, 0);
//	dst = load_transparency(ctrl->bas->img, 3072, 1728);
//	src = load_transparency(ctrl->bas->imgp, 3072, 1728);
//	put_img_to_img(dst, src, 0, 0);
}

//Check Transparency