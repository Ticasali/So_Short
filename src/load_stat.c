/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:26:03 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 11:45:07 by ticasali         ###   ########.fr       */
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
