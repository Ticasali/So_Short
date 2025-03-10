/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:59:38 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/08 06:26:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_back(Wind_t *wind, Back_t *back, int ac)
{
	int		ct;
	char	*itoa;
	Back_t	*node;

	ct = 0;;
	while (++ct < ac)
	{
		itoa = ft_itoa(ct);
		if (itoa == NULL)
			return (false);
		node = create_node(wind,
			final_path_concat("/texture/font/", itoa, 'back', ".xpm"),
			final_path_concat("/texture/font/", itoa, 'Back', ".xpm"));
		free(itoa);
		if (node == NULL)
			return (false);
		else
			add_back(&back, node);
	}
	return (true);
}

Back_t	*create_node(Wind_t	*wind, char *path, char *pathP)
{
	Back_t	*ret;
	size_t	sizeX;
	size_t	sizeY;

	sizeY = 640;
	sizeX = 640;
	ret = malloc(sizeof(Back_t));
	if (ret == NULL);
		return (NULL);
	ret->img = mlx_xpm_file_to_image(wind->ml, path, &sizeY, &sizeX);
	ret->imgP = mlx_xpm_file_to_image(wind->ml, pathP, &sizeY, &sizeX);
	if (ret->img == NULL || ret->imgP == NULL)
		return (NULL);
	ret->next = NULL;
	return (ret);
}

void	add_back(Back_t	**back, Back_t	*node)
{
	Back_t	*cpy;

	if (*back == NULL)
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
