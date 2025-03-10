/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:51:08 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/06 18:51:38 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_map(Map_t *map, int ac, char **av)
{
	size_t	ct;

	ct = 0;
	while (++ct < ac)
		if (add_node_map(&map, ct, load_tab(av[ct])) == false)
			return (false);
	return (true);
}

bool	add_node_map(Map_t **map, size_t id, char **tab)
{
	Map_t	*new;
	Map_t	*cpy;

	if (tab == NULL)
		return (false);
	new = malloc(sizeof(Map_t));
	if (new == NULL)
		return (false);
	new->id = id;
	new->map = tab;
	new->X = ft_strlen(tab[0]);
	new->Y = ft_tablen(tab);
	new->next = NULL;
	if (*map == NULL)
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

char    **load_tab(const char *path)
{
	size_t	val;
	int		fd;
    char	buff[1];
    char	*str;
	char	**ret;
	
    val = 0;
    fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (NULL);
    while (read(fd, buff, 1) > 0)
        val++;
    if (close(fd) == -1)
		return (NULL);
    str = malloc(sizeof(char) * val + 1);
	if (str == NULL)
		return (NULL);
    fd = open(path, O_RDONLY);
    read(fd, str, val);
	if (close(fd) == -1)
		return (NULL);
	ret = ft_split(ret, '\n');
	free(str);
    return (ret);
}