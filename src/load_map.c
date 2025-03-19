/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:51:08 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/18 22:37:51 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

t_Map	*load_map(int ac, char **av)
{
	int		ct;
	t_Map	*ret;

	ct = 0;
	while (++ct < ac)
		if (add_node_map(&ret, ct, load_tab(av[ct])) == false)
			return (NULL);
	return (ret);
}

bool	add_node_map(t_Map **map, size_t id, char **tab)
{
	t_Map	*new;
	t_Map	*cpy;

	if (tab == NULL)
		return (false);
	new = malloc(sizeof(t_Map));
	if (new == NULL)
		return (false);
	new->id = id;
	new->map = tab;
	new->x = ft_strlen(tab[0]);
	new->y = ft_tablen(tab);
	new->next = NULL;
	if (id == 1)
	{
		*map = new;
		return (true);
	}
	cpy = *map;
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = new;
	return (true);
}

char	**load_tab(const char *path)
{
	size_t	val;
	int		fd;
//	char	buff[4096];
	char	*str;
	char	**ret;

	val = 0;
	fd = open(path, O_RDONLY);
	str = malloc(sizeof(char) * 4096);
	set_zero(str, 4096);
	if (fd <= 0)
		return (NULL);
	read(fd, str, 4096);
	if (close(fd) == -1)
		return (NULL);
//	str = malloc(sizeof(char) * val + 1);
	if (str == NULL)
		return (NULL);
//	fd = open(path, O_RDONLY);
//	read(fd, str, val);
//	if (close(fd) == -1)
//		return (NULL);
	ret = ft_split(str, '\n');
	free(str);
	return (ret);
}
