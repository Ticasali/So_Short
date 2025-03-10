/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:02:04 by ticasali          #+#    #+#             */
/*   Updated: 2025/02/18 13:14:03 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

void	error(char *str, Control_t *Ctrl)
{
	write(2, str, ft_strlen(str));
	free_all(Ctrl);
	exit(-1);
}