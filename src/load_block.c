/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:57:44 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 10:17:49 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_block_struct(t_Control *ctrl)
{
	int	ct;

	ct = 0;
	ctrl->bls = load_block(ctrl->ws, pars_map_block(&ctrl->ms, ctrl->statement), ctrl->statement);
	if (ctrl->bls == NULL)
		return (false);
	return (true);
}

t_Map	*pars_map_block(t_Map **map, size_t ct_m)
{
	t_Map	*cpy;
	size_t	ct;

	cpy = *map;
	ct = 0;
	while (ct < ct_m)
	{
		cpy = cpy->next;
		++ct;
	}
	return (cpy);
}

t_Block	*load_block(t_Wind *wind, t_Map *map, int ct_map)
{
	size_t	ct_y;
	size_t	ct_x;
	int		*pos = malloc(sizeof(int) * 4);
	t_Block	*ret;

	ct_y = -1;
	pos[2] = ct_map + 1;
	pos[3] = 0;
	while (map->map[++ct_y] != NULL)
	{
		ct_x = 0;
		while (map->map[ct_y][ct_x] != '\0')
		{
			if (map->map[ct_y][ct_x] == '1')
			{
				pos[0] = ct_y;
				pos[1] = ct_x;
				if (add_node_block(wind, &ret, map, pos) == false)
					return (NULL);
				++pos[3];
			}
			++ct_x;
		}
	}
	free(pos);
	return (ret);
}

bool	add_node_block(t_Wind *wind, t_Block **block, t_Map *map, int *pos)
{
	t_Block	*new;
	t_Block	*cpy;

	new = malloc(sizeof(t_Block));
	if (new == NULL)
		return (false);
	new->img = gen_background(wind, map, pos, true);
	new->imgp = gen_background(wind, map, pos, false);
	if (new->img == NULL || new->imgp == NULL)
		return (false);
	new->xmin = pos[1] * 64;
	new->xmax = pos[1] * 64 + 64;
	new->ymax = pos[0] * 64 + 64;
	new->ymin = pos[0] * 64;
	new->next = NULL;
	if (pos[3] == 0)
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
