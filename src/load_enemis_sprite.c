/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemis_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:36:39 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/24 09:36:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_enemis_sprite(t_Wind *wind, t_Enemi *enem)
{
	enem->yframe = 3;
	enem->xframe = 0;
	enem->imgr = load_enem_animation(wind, true);
	if (enem->imgr == NULL)
		return (false);
	enem->imgl = load_enem_animation(wind, false);
	if (enem->imgl == NULL)
		return (false);
	return (true);
}

void	***load_enem_animation(t_Wind *wind, bool check)
{
	void	***ret;

	ret = malloc(sizeof(void **) * 4);
	if (ret == NULL)
		return (NULL);
	ret[0] = load_enem_sprite(wind, check,
			"./texture/enemis/Tree/Attack/attack", 6);
	if (ret[0] == NULL)
		return (NULL);
	ret[1] = load_enem_sprite(wind, check,
			"./texture/enemis/Tree/Damage/damage", 5);
	if (ret[1] == NULL)
		return (NULL);
	ret[2] = load_enem_sprite(wind, check,
			"./texture/enemis/Tree/Death/death", 6);
	if (ret[2] == NULL)
		return (NULL);
	ret[3] = load_enem_sprite(wind, check,
			"./texture/enemis/Tree/Move/move", 5);
	if (ret[3] == NULL)
		return (NULL);
	return (ret);
}

void	**load_enem_sprite(t_Wind *wind, bool check, char *path, int sprite)
{
	void	**ret;
	int		ct;

	ret = malloc(sizeof(void *) * sprite);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (ct < sprite)
	{
		if (check == true)
			ret[ct] = load_image(wind,
					player_path_concat(path, 'R', ft_itoa(ct + 1), ".xpm"), 64, 64);
		else
			ret[ct] = load_image(wind,
					player_path_concat(path, 'L', ft_itoa(ct + 1), ".xpm"), 64, 64);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}
