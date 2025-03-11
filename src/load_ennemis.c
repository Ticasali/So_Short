/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ennemis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:09:34 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 08:04:40 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_enemis(Control_t *ctrl)
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
			if (map->map[ct_y][ct_x] == 'e')
				if (add_back_enem(load_node_enem(ctrl, ct_x, ct_y), ctrl) == false)
					return (false);
		}
	}
	return (true);
}

Enemis_t	*load_node_enem(Control_t *ctrl, size_t x, size_t y)
{
	Enemis_t	*node;

	node = malloc(sizeof(Enemis_t));
	if (node == NULL)
		return (NULL);
	if (load_enemis_sprite(ctrl->WS, node) == false)
		return (NULL);
	node->Xmax = 64 * x + 64;
	node->Ymax = 64 * y;
	node->Xmin = 64 * x;
	node->Ymin = 64 * y + 64;
	node->speed = 4;
	node->next = NULL;
	return (node);
}

bool	add_back_enem(Enemis_t *node, Control_t *ctrl)
{
	Enemis_t	*cpy;

	if (node == NULL)
		return (false);
	cpy = ctrl->ES[ctrl->Statement];
	if (cpy == NULL)
	{
		node = ctrl->ES[ctrl->Statement];
		return (true);
	}
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = node;
	return (true);
}