/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:17:09 by ticasali          #+#    #+#             */
/*   Updated: 2024/10/31 17:19:56 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int    ft_strlen(char *str)
{
    int     ret;

    ret = -1;
    while (str[++ret] != '\0')
        ;
    return (ret);
}

int     ft_tablen(char **tab)
{
    int     ret;

    ret = -1;
    while (tab[++ret])
        ;
    return (ret);
}