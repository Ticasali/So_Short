/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:52:58 by ticasali          #+#    #+#             */
/*   Updated: 2025/02/20 00:58:59 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

static void	*ft_free_all(char **tab)
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

static size_t	ft_count_words(char const *s, char c)
{
	size_t	ret;
	size_t	ct;
	size_t	check;

	ct = 0;
	ret = 0;
	check = 0;
	while (s[ct])
	{
		if (s[ct] == c)
		{
			while (s[ct] == c)
				ct++;
			check = 0;
		}
		if (s[ct] != c && s[ct] != '\0')
		{
			if (check == 0)
				ret++;
			while (s[ct] != c && s[ct] != '\0')
				ct++;
			check = 1;
		}
	}
	return (ret);
}

static char	*ft_strdup(char const *s, char c)
{
	size_t	ct;
	char	*ret;

	ct = 0;
	while (s[ct] != '\0' && s[ct] != c)
		ct++;
	ret = malloc(sizeof(char) * ct + 1);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (s[ct] != '\0' && s[ct] != c)
	{
		ret[ct] = s[ct];
		ct++;
	}
	ret[ct] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	ct;
	size_t	ct_tab;

	ret = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	ct = 0;
	ct_tab = 0;
	while (s[ct] != '\0')
	{
		while (s[ct] == c)
			ct++;
		if (s[ct] != '\0')
		{
			ret[ct_tab] = ft_strdup(&s[ct], c);
			if (ret[ct_tab] == NULL)
				return (ft_free_all(ret));
			ct_tab++;
		}
		while (s[ct] != c && s[ct] != '\0')
			ct++;
	}
	ret[ct_tab] = NULL;
	return (ret);
}
