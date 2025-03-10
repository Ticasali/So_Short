/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:57:44 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/06 18:49:44 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_block_struct(Control_t **ctrl, int ac)
{
	size_t	ct;

	ct = 0;
	ctrl[0]->BlS = malloc(sizeof(Block_t) * (ac - 1));
		if (ctrl[0]->BlS == NULL)
			return (false);
	while (++ct < ac)
		if (pars_map_for_block(ctrl[0]->WS, ctrl[0]->BlS[ct], &ctrl[0]->MS, ct) == false)
			return (false);
	return (true);
}
/*
size_t	find_map_to_pars(size_t	ac)
{
	size_t	ct;
	size_t	res;

	ct = 0;
	res = 1;
	while (ct < ac)
	{
		++ct;
		if (ct % 2 == 0)
			++res;
	}
	return (res);
}
*/
bool	pars_map_for_block(Wind_t *wind, Block_t *block, Map_t **map, size_t ct_map)
{
	Map_t	*cpy;
	size_t	ct;

	cpy = *map;
	ct = 0;
	while (ct < ct_map)
	{
		cpy = cpy->next;
		++ct;
	}
	if (load_block(wind, block, cpy, ct) == false)
		return (false);
	return (true);
}

bool	load_block(Wind_t *wind, Block_t *block, Map_t *map, size_t ct_map)
{
	size_t	ct_y;
	size_t	ct_x;
	int		pos[3];

	ct_y = -1;
	pos[3] = ct_map;
	while (map->map[++ct_y] != NULL)
	{
		ct_x = -1;
		while (map->map[ct_y][++ct_x] != '\0')
		{
			if (map->map[ct_y][ct_x] == '1')
			{
				pos[0] = ct_y;
				pos[1] = ct_x;
				if (add_node_block(wind, &block, map, pos) == false)
					return (false);
			}
		}
	}
	return (true);
}

bool	add_node_block(Wind_t *wind, Block_t **block, Map_t *map, int *pos)
{
	Block_t	*new;
	Block_t	*cpy;

	new = malloc(sizeof(Block_t));
	if (new == NULL)
		return (false);
	new->img = gen_background(wind, map, pos, true);
	new->imgP = gen_background(wind, map, pos, false);
	if (new->img == NULL || new->imgP == NULL)
		return (false);
	new->Xmin = pos[1] * 64;
	new->Xmax = pos[1] * 64 + 64;
	new->Ymax = pos[0] * 64 + 64;
	new->Ymin = pos[0] * 64;
	new->next = NULL;
	if (*block == NULL)
	{
		*block = new;
		return (true);
	}
	cpy = *block;
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = new;
	return (true);
}