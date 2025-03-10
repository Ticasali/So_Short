/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:24:42 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/09 20:33:22 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	***load_button_menu(Wind_t *wind)
{
	void	***ret;

	ret = malloc(sizeof(void **) * 3);
	if (ret == NULL)
		return (NULL);
	ret[0] = load_button_menu_sprite(wind, "/texture/button/menu/new", 3);
	if (ret[0] == NULL)
		return (NULL);
	ret[1] = load_button_menu_sprite(wind, "/texture/button/menu/continue", 3);
	if (ret[1] == NULL)
		return (NULL);
	ret[2] = load_button_menu_sprite(wind, "/texture/button/menu/quit", 3);
	if (ret[2] == NULL)
		return (NULL);
}

void	**load_button_menu_sprite(Wind_t *wind, char const *path, int sprite)
{
	void	**ret;
	size_t	ct;

	ret = malloc(sizeof(void *) * sprite);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (ct < sprite)
	{
		ret[ct] = load_image(wind
				, menu_path_concat(path, ft_itoa(ct), ".xpm"), 300, 150);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}
