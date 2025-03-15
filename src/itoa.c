/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:56:31 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 23:55:08 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"
#include "limits.h"

char	*ft_revstr(char *ret)
{
	size_t	fst;
	size_t	lst;
	char	c;

	lst = 0;
	fst = 0;
	while (ret[lst])
		lst++;
	lst--;
	if (ret[fst] == '-')
		fst++;
	while (fst < lst)
	{
		c = ret[fst];
		ret[fst] = ret[lst];
		ret[lst] = c;
		fst++;
		lst--;
	}
	return (ret);
}

size_t	ft_allocated_value(int n)
{
	size_t	ret;

	ret = 0;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n *= -1;
		ret++;
	}
	while (n >= 10)
	{
		n /= 10;
		ret++;
	}
	return (ret + 1);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	ct;
	long	cast;

	ct = 0;
	cast = (long)(n);
	ret = malloc(sizeof(char) * ft_allocated_value(n) + 1);
	if (ret == NULL)
		return (NULL);
	if (cast < 0)
	{
		cast *= -1;
		ret[ct++] = '-';
	}
	while (cast >= 10)
	{
		ret[ct++] = (cast % 10) + 48;
		cast /= 10;
	}
	ret[ct] = cast + 48;
	ret[ct + 1] = '\0';
	return (ft_revstr(ret));
}
