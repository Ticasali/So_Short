/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 04:08:13 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:51 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_coin_struct(t_Control *ctrl)
{
	ctrl->cs = load_coin(ctrl->ws, pars_map_coin(&ctrl->ms, ctrl->statement));
	if (ctrl->cs == NULL)
		return (false);
	return (true);

}

t_Map	*pars_map_coin(t_Map **map, size_t ct_m)
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

t_Coin	*load_coin(t_Wind *wind, t_Map *map)
{
	size_t	ct_y;
	size_t	ct_x;
	t_Coin	*ret;
	int		*pos = malloc(sizeof(int) * 3);

	ct_y = -1;
	pos[2] = 0;
	while (map->map[++ct_y] != NULL)
	{
		ct_x = 0;
		while (map->map[ct_y][ct_x] != '\0')
		{
			if (map->map[ct_y][ct_x] == 'C')
			{
				pos[0] = ct_y;
				pos[1] = ct_x;
				if (add_node_coin(wind, pos, &ret) == false)
					return (NULL);
				++pos[2];
			}
			++ct_x;
		}
	}
	free(pos);
	return (ret);
}

bool	add_node_coin(t_Wind *wind, int *pos, t_Coin **coin)
{
	t_Coin	*node;
	t_Coin	*cpy;

	node = malloc(sizeof(t_Coin));
	if (node == NULL)
		return (NULL);
	node->img = load_coin_sprite(wind);
	if (node->img == NULL)
		return (NULL);
	node->frame = 0;
	node->xmax = 64 * pos[1] + 64;
	node->ymax = 64 * pos[0] + 64;
	node->xmin = 64 * pos[1];
	node->ymin = 64 * pos[0];
	node->life = true;
	node->next = NULL;
	if (pos[2] == 0)
	{
		*coin = node;
		return (true);
	}
	cpy = *coin;
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = node;
	return (true);
}
