/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:52:11 by ticasali          #+#    #+#             */
/*   Updated: 2025/02/20 16:12:03 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_window(Wind_t	*wind)
{
	wind->ml = mlx_init();
	if (wind->ml == NULL)
		return (false);
	wind->win = mlx_new_window(wind->ml, 1280, 960, "ELAYM");
	return (true);
}
