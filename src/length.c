/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:03:45 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 03:47:40 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

size_t	ft_strlen(char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret] != '\0')
		++ret;
	return (ret);
}

size_t	ft_tablen(char **tab)
{
	size_t	ret;

	ret = 0;
	while (tab[ret] != NULL)
		++ret;
	return (ret);
}