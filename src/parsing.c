/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:05:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 08:48:52 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	check_parsing(Control_t *ctrl)
{
	Map_t	*map;
	size_t	ct;

	ct = 0;
	map = ctrl->MS;
	while (ct < ctrl->Statement)
	{
		map = map->next;
		++ct;
	}
	if (check_lenght(map->map) == false)
		return (false);
	if (check_char(map->map) == false)
		return (false);
	if (check_border(map->map) == false)
		return (false);
	if (check_need_char(map->map) == false)
		return (false);
	if (check_double_char(map->map) == false)
		return (false);
	if (check_pathfinding(map->map) == false)
		return (false);
	return (true);
}