/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:29:43 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 15:21:21 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

char	**tab_cpy(char **tab)
{
	char	**ret;
	size_t	ct;

	ret = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (tab[ct] != NULL)
	{
		ret[ct] = ft_strcpy(tab[ct]);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	ret[ct] = NULL;
	return (ret);
}

char	*ft_strcpy(char	*str)
{
	char	*ret;
	size_t	ct;

	ret = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (str[ct] != '\0')
	{
		ret[ct] = str[ct];
		++ct;
	}
	ret[ct] = '\0';
	return (ret);
}

void	set_zero(char *str, size_t num)
{
	size_t	ct;

	ct = 0;
	while (ct < num)
	{
		str[ct] = '\0';
		++ct;
	}
}