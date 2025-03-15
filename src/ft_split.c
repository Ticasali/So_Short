/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:52:58 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 04:12:32 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	*ft_free_all(char **tab)
{
	size_t	ct;

	ct = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[ct])
	{
		free(tab[ct]);
		ct++;
	}
	free(tab);
	return (NULL);
}

size_t	ft_count_words(char *str, char c)
{
	size_t	ret;
	size_t	ct;
	size_t	check;

	ct = 0;
	ret = 0;
	check = 0;
	while (str[ct])
	{
		if (str[ct] == c)
		{
			while (str[ct] == c)
				ct++;
			check = 0;
		}
		if (str[ct] != c && str[ct] != '\0')
		{
			if (check == 0)
				ret++;
			while (str[ct] != c && str[ct] != '\0')
				ct++;
			check = 1;
		}
	}
	return (ret);
}

char	*ft_strdup(char *str, char c)
{
	size_t	ct;
	char	*ret;

	ct = 0;
	while (str[ct] != '\0' && str[ct] != c)
		ct++;
	ret = malloc(sizeof(char) * ct + 1);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (str[ct] != '\0' && str[ct] != c)
	{
		ret[ct] = str[ct];
		ct++;
	}
	ret[ct] = '\0';
	return (ret);
}

char	**ft_split(char *str, char c)
{
	char	**ret;
	size_t	ct;
	size_t	ct_tab;

	ret = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (ret == NULL)
		return (NULL);
	ct = 0;
	ct_tab = 0;
	while (str[ct] != '\0')
	{
		while (str[ct] == c)
			ct++;
		if (str[ct] != '\0')
		{
			ret[ct_tab] = ft_strdup(&str[ct], c);
			if (ret[ct_tab] == NULL)
				return (ft_free_all(ret));
			ct_tab++;
		}
		while (str[ct] != c && str[ct] != '\0')
			ct++;
	}
	ret[ct_tab] = NULL;
	return (ret);
}
