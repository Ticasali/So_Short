/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:48:30 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 16:45:05 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	reset_window(t_Control *ctrl)
{
	size_t	ct;
	t_Back	*back;
	t_Trspy	dst;
	t_Trspy src;

	ct = 0;
	back = ctrl->bas;
	while (ct != ctrl->statement)
	{
		back = back->next;
		++ct;
	}
	dst = load_transparency(ctrl->bas->img, 3072, 1728);
	src = load_transparency(ctrl->bas->imgp, 3072, 1728);
	put_img_to_img(dst, src, 0, 0);

}