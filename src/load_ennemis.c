/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ennemis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:09:34 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 04:52:05 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_enemis(t_Control *ctrl)
{
	size_t	ct_y;
	size_t	ct_x;
	t_Map	*map;
	size_t	ct;

	ct_y = -1;
	ct = -1;
	map = ctrl->ms;
	while (++ct < ctrl->statement)
		map = map->next;
	while (map->map[++ct_y] != NULL)
	{
		ct_x = -1;
		while (map->map[ct_y][++ct_x] != '\0')
		{
			if (map->map[ct_y][ct_x] == 'e')
				if (add_back_enem(load_node_enem(ctrl, ct_x, ct_y),
						ctrl) == false)
					return (false);
		}
	}
	return (true);
}

t_Enemi	*load_node_enem(t_Control *ctrl, size_t x, size_t y)
{
	t_Enemi	*node;

	node = malloc(sizeof(t_Enemi));
	if (node == NULL)
		return (NULL);
	if (load_enemis_sprite(ctrl->ws, node) == false)
		return (NULL);
	node->xmax = 64 * x + 64;
	node->ymax = 64 * y;
	node->xmin = 64 * x;
	node->ymin = 64 * y + 64;
	node->speed = 4;
	node->next = NULL;
	return (node);
}

bool	add_back_enem(t_Enemi *node, t_Control *ctrl)
{
	t_Enemi	*cpy;

	if (node == NULL)
		return (false);
	cpy = ctrl->es;
	if (cpy == NULL)
	{
		node = ctrl->es;
		return (true);
	}
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = node;
	return (true);
}
