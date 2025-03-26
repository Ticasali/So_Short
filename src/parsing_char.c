/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:23:00 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 09:50:01 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 't' || c == 'C' || c == 'B')
		return (true);
	return (false);
}

bool	check_char(char **map)
{
	size_t	ct_y;
	size_t	ct_x;

	ct_y = 0;
	while (map[ct_y] != NULL)
	{
		ct_x = 0;
		while (map[ct_y][ct_x] != '\0')
		{
			if (valid_char(map[ct_y][ct_x]) == false)
				return (false);
			++ct_x;
		}
		++ct_y;
	}
	return (true);
}

bool	check_need_char(char **map)
{
	size_t	ct_y;
	size_t	ct_x;
	bool	check[3];

	ct_y = -1;
	check[0] = false;
	check[1] = false;
	check[2] = false;
	while (map[++ct_y] != NULL)
	{
		ct_x = -1;
		while (map[ct_y][++ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'P')
				check[0] = true;
			if (map[ct_y][ct_x] == 'C')
				check[1] = true;
			if (map[ct_y][ct_x] == 'E')
				check[2] = true;
		}
	}
	if (check[0] == false || check[1] == false || check[2] == false)
		return (false);
	return (true);
}

bool	check_double_char(char **map)
{
	size_t	ct_y;
	size_t	ct_x;
	int		check[2];

	ct_y = -1;
	check[0] = 0;
	check[1] = 0;
	while (map[++ct_y] != NULL)
	{
		ct_x = -1;
		while (map[ct_y][++ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'P')
				++check[0];
			if (map[ct_y][ct_x] == 'E')
				++check[1];
		}
	}
	if (check[0] > 1 || check[1] > 1)
		return (false);
	return (true);
}
