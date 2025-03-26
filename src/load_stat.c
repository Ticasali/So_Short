/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:26:03 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:52:54 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

t_Stat	*load_stat(void)
{
	t_Stat	*ret;

	ret = malloc(sizeof(t_Stat));
	if (ret == NULL)
		return (NULL);
	ret->hp = 10;
	ret->damage = 1;
	ret->speed = 10;
	return (ret);
}

t_Stat	*load_stat_boss(void)
{
	t_Stat	*ret;

	ret = malloc(sizeof(t_Stat));
	if (ret == NULL)
		return (NULL);
	ret->hp = 10;
	ret->damage = 1;
	ret->speed = 8;
	return (ret);
}