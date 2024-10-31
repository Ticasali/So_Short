/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:06:39 by ticasali          #+#    #+#             */
/*   Updated: 2024/10/30 23:53:40 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

void    ft_move_up(str_t *Data)
{
    if (Data->map[Data->Y - 1][Data->X] == '0' || Data->map[Data->Y - 1][Data->X] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y - 1][Data->X] = 'P';
        Data->Y--;
    }
    ft_puttab(Data->map);
}

void    ft_move_down(str_t *Data)
{
    if (Data->map[Data->Y + 1][Data->X] == '0' || Data->map[Data->Y + 1][Data->X] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y + 1][Data->X] = 'P';
        Data->Y++;
    }
    ft_puttab(Data->map);
}

void    ft_move_left(str_t *Data)
{
    if (Data->map[Data->Y][Data->X - 1] == '0' || Data->map[Data->Y][Data->X - 1] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X - 1] = 'P';
        Data->X--;
    }
    ft_puttab(Data->map);
}

void    ft_move_right(str_t *Data)
{
    if (Data->map[Data->Y][Data->X + 1] == '0' || Data->map[Data->Y][Data->X + 1] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X + 1] = 'P';
        Data->X++;
    }
    ft_puttab(Data->map);
}