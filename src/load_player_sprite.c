/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:00:35 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/09 00:26:57 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	**load_player_sprite(Wind_t *wind, bool check, char const *path, int sprite)
{
	void	**ret;
	size_t	ct;

	ret = malloc(sizeof(void *) * sprite);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (ct < sprite)
	{
		if (check == true)
			ret[ct] = load_image(wind
				, player_path_concat(path, 'R', ft_itoa(ct), ".xpm"), 864, 384);
		else
			ret[ct] = load_image(wind
				, player_path_concat(path, 'L', ft_itoa(ct), ".xpm"), 864, 384);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}