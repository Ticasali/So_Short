/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:00:25 by ticasali          #+#    #+#             */
/*   Updated: 2024/10/31 23:50:39 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int     ct;

    ct = -1;
    while (str[++ct] != '\0')
        ft_putchar(str[ct]);
}

void    ft_puttab(char **map)
{
    int     ctY;

    ctY = -1;
    while (map[++ctY] != NULL)
    {
        ft_putstr(map[ctY]);
        ft_putchar('\n');
    }
    ft_putchar('\n');
}

int     ft_find_player(char **map, char c)
{
    int     ctY;
    int     ctX;

    ctY = -1;
    while (map[++ctY] != NULL)
    {
        ctX = -1;
        while (map[ctY][++ctX] != '\0')
        {
            if (map[ctY][ctX] == 'P')
            {
                if (c == 'X')
                    return (ctX);
                if (c == 'Y')
                    return (ctY);
            }
        }
    }
    return (0);
}