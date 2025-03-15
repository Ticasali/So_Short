/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:02:04 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 03:26:16 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	error(char *str, t_Control *ctrl)
{
	(void)ctrl;
	write(2, str, ft_strlen(str));
	exit(-1);
}
//	free_all(ctrl);