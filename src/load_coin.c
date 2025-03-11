/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 04:08:13 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 05:48:04 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_coin(Control_t *ctrl)
{
	size_t	ct_y;
	size_t	ct_x;
	Map_t	*map;
	size_t	ct;

	ct_y = -1;
	ct = -1;
	map = ctrl->MS;
	while (++ct < ctrl->Statement)
		map = map->next;
	while (map->map[++ct_y] != NULL)
	{
		ct_x = -1;
		while (map->map[ct_y][++ct_x] != '\0')
		{
			if (map->map[ct_y][ct_x] == 'C')
				if (add_back_coin(load_node_coin(ctrl, ct_x, ct_y), ctrl) == false)
					return (false);
		}
	}
	return (true);
}

Coin_t	*load_node_enem(Control_t *ctrl, size_t x, size_t y)
{
	Coin_t	*node;

	node = malloc(sizeof(Coin_t));
	if (node == NULL)
		return (NULL);
	node->img = load_coin_sprite(ctrl->WS);
	if (node->img == NULL)
		return (NULL);
	node->Frame = 0;
	node->Xmax = 64 * x + 64;
	node->Ymax = 64 * y;
	node->Xmin = 64 * x;
	node->Ymin = 64 * y + 64;
	node->next = NULL;
	return (node);
}

bool	add_back_coin(Coin_t *node, Control_t *ctrl)
{
	Coin_t	*cpy;

	if (node == NULL)
		return (false);
	cpy = *ctrl->ES;
	if (cpy == NULL)
	{
		node = ctrl->ES;
		return (true);
	}
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = node;
	return (true);
}