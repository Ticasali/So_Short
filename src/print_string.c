/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:03:48 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 15:16:04 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	print_string(t_Control *ctrl, char *str, int x, int y)
{
	size_t	ct;

	ct = 0;
	while (str[ct] != '\0')
	{
		mlx_put_image_to_window(ctrl->ws->ml, ctrl->ws->win,
			ctrl->fs->imgfont[str[ct] - 97], (ct * 64) + x, y);
		++ct;
	}
}
