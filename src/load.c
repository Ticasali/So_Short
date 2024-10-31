/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:02:53 by ticasali          #+#    #+#             */
/*   Updated: 2024/10/31 14:32:39 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int     ft_count_line(char  *str)
{
    int     ret;
    int     ct;

    ct = -1;
    ret = 0;
    while (str[++ct])
        if (str[ct] == '\n')
            ret++;
    return (ret);
}

char    *ft_strcpy_dup(char *str)
{
    char    *ret;
    int     ct;

    ct = 0;
    while (str[ct] != '\0' && str[ct] != '\n')
        ct++;
    ret = malloc(sizeof(char) * ct + 1);
    ct = 0;
    while (str[ct] != '\0' && str[ct] != '\n')
    {
        ret[ct] = str[ct];
        ct++;
    }
    ret[ct] = '\0';
    return (ret);
}

char    **ft_split(char *str)
{
    char    **ret;
    int     ct;
    int     y;

    ret = malloc(sizeof(char *) * (ft_count_line(str) + 1));
    ct = 0;
    y = -1;
    while (str[ct])
    {
        ret[++y] = ft_strcpy_dup(&str[ct]);
        while (str[ct] != '\n' && str[ct] != '\0')
            ct++;
        while (str[ct] == '\n')
            ct++;
    }
    ret[y + 1] = NULL;
    return (ret);
}

char    **load_tab(const char *path)
{
    int val;
    int fd;
    char buf[1];
    char *ret;
    val = 0;

    fd = open(path, O_RDONLY);
    while (read(fd, buf, 1) > 0)
        val++;
    printf("%d\n", val);
    close(fd);
    ret = malloc(sizeof(char) * val + 1);
    fd = open(path, O_RDONLY);
    read(fd, ret, val);
    return (ft_split(ret));
}