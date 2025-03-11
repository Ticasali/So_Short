/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pathfinding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:23:21 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 11:15:43 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	check_pathfinding(char **map)
{
	char	**cpy;

	cpy = tab_cpy(map);
	flood_map(cpy);
	if (check_map_coin(cpy) == false)
	{
		free(cpy);
		return (false);
	}
	if (check_map_end(cpy) == false)
	{
		free(cpy);
		return (false);
	}
	free(cpy);
	return (true);
}

bool	check_map_coin(char **map)
{
	size_t	ct_x;
	size_t	ct_y;

	ct_y = 0;
	while (map[ct_y] != NULL)
	{
		ct_x = 0;
		while (map[ct_y][ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'C')
				return (false);
			++ct_x;
		}
		++ct_y;
	}
	return (true);
}

bool	check_map_end(char **map)
{
	size_t	ct_x;
	size_t	ct_y;

	ct_y = 0;
	while (map[ct_y] != NULL)
	{
		ct_x = 0;
		while (map[ct_y][ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'E')
				if (map[ct_y][ct_x] == '0' || map[ct_y][ct_x] == '0'
					|| map[ct_y][ct_x] == '0' || map[ct_y][ct_x] == '0')
					return (false);
			++ct_x;
		}
		++ct_y;
	}
	return (true);
}

char	**flood_map(char **map)
{
	size_t	ct_y;
	size_t	ct_x;
	bool	check;

	ct_y = -1;
	check = false;
	while (map[++ct_y] != NULL)
	{
		ct_x = -1;
		while (map[ct_y][++ct_x] != '\0')
		{
			if (map[ct_y][ct_x] == 'P' || map[ct_y][ct_x] == '2')
				if (change_map(map, ct_y, ct_x) == true)
					check = true;
		}
	}
	if (check == true)
		flood_map(map);
	return (map);
}

bool	change_map(char **map, int y, int x)
{
	bool	verif;

	verif = false;
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
	{
		map[y - 1][x] = '2';
		verif = true;
	}
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
	{
		map[y + 1][x] = '2';
		verif = true;
	}
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	{
		map[y][x - 1] = '2';
		verif = true;
	}
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
	{
		map[y][x + 1] = '2';
		verif = true;
	}
	return (verif);
}