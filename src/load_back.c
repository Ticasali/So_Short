/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:59:38 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/25 16:45:53 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

t_Back	*load_back(t_Wind *wind, int ac)
{
	int		ct;
	char	*itoa;
	t_Back	*ret;
	t_Back	*node;

	ct = 0;
	while (++ct < ac)
	{
		itoa = ft_itoa(ct);
		if (itoa == NULL)
			return (NULL);
		node = create_node(wind,
				back_path_concat("./texture/back/", itoa, 'b', "ack.xpm"),
				back_path_concat("./texture/back/", itoa, 'B', "ack.xpm"));
		free(itoa);
		if (node == NULL)
			return (NULL);
		else
			add_back(&ret, node, ct);
	}
	return (ret);
}

t_Back	*create_node(t_Wind	*wind, char *path, char *pathp)
{
	t_Back	*ret;
	int		sizex;
	int		sizey;

	sizey = 576;
	sizex = 1536;
	ret = malloc(sizeof(t_Back));
	if (ret == NULL)
		return (NULL);
	ret->img = load_image(wind, path, 3072, 1728);
	ret->imgp = load_image(wind, pathp, 3072, 1728);
	if (ret->img == NULL || ret->imgp == NULL)
		return (NULL);
	ret->next = NULL;
	return (ret);
}

void	add_back(t_Back	**back, t_Back *node, int ct)
{
	t_Back	*cpy;

	if (ct == 1)
	{
		*back = node;
		return ;
	}
	cpy = *back;
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = node;
	return ;
}
