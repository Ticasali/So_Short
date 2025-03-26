/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:14:33 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 10:05:18 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

size_t	find_player(char **map, bool check)
{
	size_t	ct_y;
	size_t	ct_x;

	ct_y = 0;
	while (map[ct_y] != NULL)
	{
		ct_x = 0;
		while (map[ct_y][ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'P')
			{
				if (check == true)
					return (ct_y);
				else
					return (ct_x);
			}
			++ct_x;
		}
		++ct_y;
	}
	return (0);
}

size_t	find_boss(char **map, bool check)
{
	size_t	ct_y;
	size_t	ct_x;

	ct_y = 0;
	while (map[ct_y] != NULL)
	{
		ct_x = 0;
		while (map[ct_y][ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'B')
			{
				if (check == true)
					return (ct_y);
				else
					return (ct_x);
			}
			++ct_x;
		}
		++ct_y;
	}
	return (0);
}
