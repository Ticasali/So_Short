/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:51:25 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 01:13:25 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

Menu_t	*load_menu_struct(Wind_t *wind)
{
	Menu_t	*menu;

	menu = malloc(sizeof(Menu_t));
	if (menu == NULL)
		return (NULL);
	menu->background = load_background_menu_sprite(wind, "/texture/background/menu", 6);
	if (menu->background == NULL)
		return (NULL);
	menu->button = load_menu_button(wind);
	if (menu->button == NULL)
		return (NULL);
	menu->FrameBack = 0;
	menu->FrameButton = load_frame_button();
	if (menu->FrameButton == NULL)
		return (NULL);
	menu->time = get_time();
	menu->xmouse = 0;
	menu->ymouse = 0;
	menu->statement = 0;
	return (menu);
}

void	**load_background_menu_sprite(Wind_t *wind, char const *path, int sprite)
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
				, menu_path_concat(path, ft_itoa(ct), ".xpm"), 1600, 1600);
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