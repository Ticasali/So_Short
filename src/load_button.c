/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:24:42 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/14 08:03:04 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	***load_button_menu(t_Wind *wind)
{
	void	***ret;

	ret = malloc(sizeof(void **) * 3);
	if (ret == NULL)
		return (NULL);
	ret[0] = load_button_menu_sprite(wind, "./texture/button/menu/new", 3);
	if (ret[0] == NULL)
		return (NULL);
	ret[1] = load_button_menu_sprite(wind, "./texture/button/menu/continue", 3);
	if (ret[1] == NULL)
		return (NULL);
	ret[2] = load_button_menu_sprite(wind, "./texture/button/menu/quit", 3);
	if (ret[2] == NULL)
		return (NULL);
	return (ret);
}

void	**load_button_menu_sprite(t_Wind *wind, char const *path, int sprite)
{
	void	**ret;
	int		ct;

	ret = malloc(sizeof(void *) * sprite);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (ct < sprite)
	{
		ret[ct] = load_image(wind,
				menu_path_concat(path, ft_itoa(ct + 1), ".xpm"), 50, 100);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}
