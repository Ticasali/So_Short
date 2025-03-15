/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:52:11 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 06:14:44 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_window(t_Wind	*wind)
{
	wind->ml = mlx_init();
	if (wind->ml == NULL)
		return (false);
	wind->win = mlx_new_window(wind->ml, 3072, 1728, "ELAYM");
	if (wind->win == NULL)
		return (false);
	return (true);
}
