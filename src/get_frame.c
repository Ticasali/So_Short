/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:31:39 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/19 12:16:31 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int		*load_first_frame(void)
{
	int		*ret;

	ret = malloc(sizeof(int) * 9);
	if (ret == NULL)
		return (NULL);

	ret[0] = 10;
	ret[1] = 7;
	ret[2] = 17;
	ret[3] = 5;
	ret[4] = 12;
	ret[5] = 9;
	ret[6] = 7;
	ret[7] = 19;
	ret[8] = 7;
	return (ret);
}

int		*load_second_frame(void)
{
	int		*ret;

	ret = malloc(sizeof(int) * 9);
	if (ret == NULL)
		return (NULL);
	ret[0] = 6;
	ret[1] = 7;
	ret[2] = 31;
	ret[3] = 6;
	ret[4] = 9;
	ret[5] = 11;
	ret[6] = 7;
	ret[7] = 15;
	ret[8] = 7;
	return (ret);
}

int		**load_frame_player(void)
{
	int		**ret;

	ret = malloc(sizeof(int *) * 2);
	if (ret == NULL)
		return (NULL);
	ret[0] = load_first_frame();
	if (ret[0] == NULL)
		return (NULL);
	ret[1] = load_second_frame();
	if (ret[1] == NULL)
		return (NULL);
	return (ret);
}