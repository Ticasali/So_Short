/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:26:03 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 23:07:34 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

Stat_t	*load_stat(void)
{
	Stat_t	*ret;

	ret = malloc(sizeof(Stat_t));
	if (ret == NULL)
		return (NULL);
	ret->hp = 10;
	ret->damage = 1;
	ret->speed = 5;
	return (ret);
}
