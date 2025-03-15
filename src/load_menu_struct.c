/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:51:25 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 08:58:09 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

t_Menu	*load_menu_struct(t_Wind *wind)
{
	t_Menu	*menu;

	menu = malloc(sizeof(t_Menu));
	if (menu == NULL)
		return (NULL);
	menu->background = load_back_menu_img(wind,
			"./texture/back/menu/", 3);
	if (menu->background == NULL)
		return (NULL);
	menu->button = load_button_menu(wind);
	if (menu->button == NULL)
		return (NULL);
	menu->frameback = 0;
	menu->framebutton = load_frame_button();
	if (menu->framebutton == NULL)
		return (NULL);
	menu->time = get_time();
	menu->xmouse = 0;
	menu->ymouse = 0;
	menu->statement = 0;
	return (menu);
}

void	**load_back_menu_img(t_Wind *wind, char const *path, int sprite)
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
				menu_path_concat(path, ft_itoa(ct + 1), ".xpm"), 1536, 576);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}

int	*load_frame_button(void)
{
	int	*ret;

	ret = malloc(sizeof(int) * 3);
	if (ret == NULL)
		return (NULL);
	ret[0] = 0;
	ret[1] = 0;
	ret[2] = 0;
	return (ret);
}
