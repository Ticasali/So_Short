/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:39:20 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 23:26:13 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	cmp;

	cmp = 0;
	while (s1[cmp] != '\0' || s2[cmp] != '\0')
	{
		if (s1[cmp] != s2[cmp])
			return (s1[cmp] - s2[cmp]);
		cmp++;
	}
	return (0);
}
