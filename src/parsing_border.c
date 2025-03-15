/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:22:43 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/14 06:49:50 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	check_border(char **map)
{
	size_t	max_x;
	size_t	max_y;

	max_x = ft_strlen(map[0]);
	max_y = ft_tablen(map);
	if (check_border_top_bot(map, max_y) == false)
		return (false);
	if (check_border_left_right(map, max_x) == false)
		return (false);
	return (true);
}

bool	check_border_top_bot(char **map, size_t y)
{
	size_t	ct;

	ct = 0;
	while (map[0][ct] != '\0')
	{
		if (map[0][ct] != '1')
			return (false);
		++ct;
	}
	ct = 0;
	while (map[y - 1][ct] != '\0')
	{
		if (map[y - 1][ct] != '1')
			return (false);
		++ct;
	}
	return (true);
}

bool	check_border_left_right(char **map, size_t x)
{
	size_t	ct;

	ct = 0;
	while (map[ct] != NULL)
	{
		if (map[ct][0] != '1')
			return (false);
		++ct;
	}
	ct = 0;
	while (map[ct] != NULL)
	{
		if (map[ct][x - 1] != '1')
			return (false);
		++ct;
	}
	return (true);
}
