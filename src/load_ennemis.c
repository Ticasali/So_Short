/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ennemis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:09:34 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 16:49:14 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_enemis_struct(t_Control *ctrl)
{
	ctrl->es = load_enemis(ctrl->ws, pars_map_coin(&ctrl->ms, ctrl->statement));
	if (ctrl->es == NULL)
		return (false);
	return (true);

}

t_Enemi	*load_enemis(t_Wind *wind, t_Map *map)
{
	size_t	ct_y;
	size_t	ct_x;
	t_Enemi	*ret;
	int		*pos = malloc(sizeof(int) * 3);

	ct_y = -1;
	pos[2] = 0;
	while (map->map[++ct_y] != NULL)
	{
		ct_x = -1;
		while (map->map[ct_y][++ct_x] != '\0')
		{
			if (map->map[ct_y][ct_x] == 't')
			{
				pos[0] = ct_y;
				pos[1] = ct_x;
				if (add_node_enem(wind, pos, &ret) == false)
					return (NULL);
				++pos[2];
			}
		}
	}
	free(pos);
	return (ret);
}

bool	add_node_enem(t_Wind *wind, int *pos, t_Enemi **enem)
{
	t_Enemi	*node;
	t_Enemi *cpy;

	node = malloc(sizeof(t_Enemi));
	if (node == NULL)
		return (NULL);
	if (load_enemis_sprite(wind, node) == false)
		return (NULL);
	node->xmax = 64 * pos[1] + 64;
	node->ymax = 64 * pos[0];
	node->xmin = 64 * pos[1];
	node->ymin = 64 * pos[0] + 64;
	node->speed = 4;
	node->dir = false;
	node->life = true;
	node->next = NULL;
	if (pos[2] == 0)
	{
		*enem = node;
		return (true);
	}
	cpy = *enem;
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = node;
	return (node);
}
