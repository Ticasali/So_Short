/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:41:17 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/12 23:53:56 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

double	atod(char *str)
{
	double	ret;
	size_t	ct;

	ct = 0;
	ret = 0;
	while (str[ct] > 47 && str[ct] < 58)
	{
		ret += str[ct] - 48;
		if ((str[++ct] > 47 && str[ct] < 58))
			ret *= 10;
	}
	ret += (double)(str[++ct] - 48) / 10;
	ret += (double)(str[++ct] - 48) / 100;
	return (ret);
}

double	get_time(void)
{
	char	*str_time;
	double	time;
	int		fd;

	str_time = malloc(sizeof(char) * 11);
	if (str_time == NULL)
		return (-1);
	fd = open("/proc/uptime", O_RDONLY);
	if (fd <= 0)
	{
		free(str_time);
		return (-1);
	}
	read(fd, str_time, 10);
	time = atod(str_time);
	if (close(fd) == -1)
		return (-1);
	free(str_time);
	return (time);
}
