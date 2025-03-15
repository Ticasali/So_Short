/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 08:39:47 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/14 11:58:05 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"
#include "../mlx_linux/mlx_int.h"

int	mlx_reset(t_xvar *xvar)
{
	xvar->end_loop = 0;
	return (0);
}
