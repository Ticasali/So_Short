/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:20:33 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 01:36:37 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	check_lenght(char **map)
{
	size_t	ct_y;
	size_t	verif;

	ct_y = 0;
	verif = ft_strlen(map[ct_y]);
	while (map[++ct_y] != NULL)
		if (ft_strlen(map[ct_y]) != verif)
			return (false);
	return (true);
}
