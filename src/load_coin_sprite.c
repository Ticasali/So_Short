/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_coin_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 04:14:39 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 04:38:48 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	**load_coin_sprite(Wind_t *wind, Coin_t *node)
{
	void	**ret;
	size_t	ct;

	ret = malloc(sizeof(void *) * 3);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (ct < 3)
	{
		ret[ct] = load_image(wind
				, menu_path_concat("/texture/coin/", ft_itoa(ct), ".xpm"), 64, 64);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}