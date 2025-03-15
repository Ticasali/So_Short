/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:11:52 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/15 05:08:37 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

char	*block_path_concat(char const *path, char *m, char c, char const *str)
{
	char	*ret;
	size_t	ct_ret;
	size_t	ct_str;
	size_t	ct_alloc;

	ct_ret = -1;
	ct_alloc = ft_strlen(path) + ft_strlen(m) + ft_strlen(str) + 1;
	ret = malloc(sizeof(char) * (ct_alloc) + 2);
	if (ret == NULL)
		return (NULL);
	ct_str = -1;
	while (path[++ct_str] != '\0')
		ret[++ct_ret] = path[ct_str];
	ct_str = -1;
	while (m[++ct_str] != '\0')
		ret[++ct_ret] = m[ct_str];
	ret[++ct_ret] = '/';
	ret[++ct_ret] = c;
	ct_str = -1;
	while (str[++ct_str] != '\0')
		ret[++ct_ret] = str[ct_str];
	ret[++ct_ret] = '\0';
	return (ret);
}

char	*back_path_concat(char const *path, char *m, char c, char const *str)
{
	char	*ret;
	size_t	ct_ret;
	size_t	ct_str;
	size_t	ct_alloc;

	ct_ret = -1;
	ct_alloc = ft_strlen(path) + ft_strlen(m) + ft_strlen(str) + 1;
	ret = malloc(sizeof(char) * (ct_alloc) + 1);
	if (ret == NULL)
		return (NULL);
	ct_str = -1;
	while (path[++ct_str] != '\0')
		ret[++ct_ret] = path[ct_str];
	ct_str = -1;
	while (m[++ct_str] != '\0')
		ret[++ct_ret] = m[ct_str];
	ret[++ct_ret] = c;
	ct_str = -1;
	while (str[++ct_str] != '\0')
		ret[++ct_ret] = str[ct_str];
	ret[++ct_ret] = '\0';
	return (ret);
}

char	*player_path_concat(char const *path, char c, char *n, char const *fil)
{
	char	*ret;
	size_t	ct_ret;
	size_t	ct_str;
	size_t	ct_alloc;

	ct_ret = -1;
	ct_alloc = ft_strlen(path) + ft_strlen(n) + ft_strlen(fil) + 1;
	ret = malloc(sizeof(char) * (ct_alloc) + 1);
	if (ret == NULL)
		return (NULL);
	ct_str = -1;
	while (path[++ct_str] != '\0')
		ret[++ct_ret] = path[ct_str];
	ct_str = -1;
	ret[++ct_ret] = c;
	while (n[++ct_str] != '\0')
		ret[++ct_ret] = n[ct_str];
	ct_str = -1;
	while (fil[++ct_str] != '\0')
		ret[++ct_ret] = fil[ct_str];
	ret[++ct_ret] = '\0';
	free(n);
	return (ret);
}

char	*menu_path_concat(char const *path, char *num, char const *file)
{
	char	*ret;
	size_t	ct_ret;
	size_t	ct_str;
	size_t	ct_alloc;

	ct_ret = -1;
	ct_alloc = ft_strlen(path) + ft_strlen(num) + ft_strlen(file);
	ret = malloc(sizeof(char) * (ct_alloc) + 1);
	if (ret == NULL)
		return (NULL);
	ct_str = -1;
	while (path[++ct_str] != '\0')
		ret[++ct_ret] = path[ct_str];
	ct_str = -1;
	while (num[++ct_str] != '\0')
		ret[++ct_ret] = num[ct_str];
	ct_str = -1;
	while (file[++ct_str] != '\0')
		ret[++ct_ret] = file[ct_str];
	ret[++ct_ret] = '\0';
	free(num);
	return (ret);
}

char	*font_path_concat(char const *path, char ascii, char const *file)
{
	char	*ret;
	size_t	ct_ret;
	size_t	ct_str;
	size_t	ct_alloc;

	ct_ret = -1;
	ct_alloc = ft_strlen(path) + ft_strlen(file) + 1;
	ret = malloc(sizeof(char) * (ct_alloc) + 1);
	if (ret == NULL)
		return (NULL);
	ct_str = -1;
	while (path[++ct_str] != '\0')
		ret[++ct_ret] = path[ct_str];
	ct_str = -1;
	ret[++ct_ret] = ascii;
	while (file[++ct_str] != '\0')
		ret[++ct_ret] = file[ct_str];
	ret[++ct_ret] = '\0';
	return (ret);
}
